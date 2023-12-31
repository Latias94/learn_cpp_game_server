#include "connect_obj.h"

#include <iostream>
#include "network.h"
#include "network_buffer.h"
#include "packet.h"

ConnectObj::ConnectObj(Network* pNetWork, int socket): _pNetWork(pNetWork), _socket(socket) {
  _recvBuffer = new RecvNetworkBuffer(DEFAULT_RECV_BUFFER_SIZE);
  _sendBuffer = new SendNetworkBuffer(DEFAULT_SEND_BUFFER_SIZE);
}

ConnectObj::~ConnectObj() {
  delete _recvBuffer;
  delete _sendBuffer;
}

void ConnectObj::Dispose() {
  std::cout << "close socket:" << _socket << std::endl;
  _sock_close(_socket);

  _recvBuffer->Dispose();
  _sendBuffer->Dispose();
}

bool ConnectObj::HasRecvData() const {
  return _recvBuffer->HasData();
}

Packet* ConnectObj::GetRecvPacket() const {
  return _recvBuffer->GetPacket();
}

bool ConnectObj::Recv() const {
  char* pBuffer = nullptr;
  while (true) {
    // 总空间数据不足一个头的大小，扩容
    if (_recvBuffer->GetEmptySize() < (sizeof(PacketHead) + sizeof(TotalSizeType))) {
      _recvBuffer->ReAllocBuffer();
    }

    // 从缓冲区中取得写位置存于 pBuffer 中，返回可写入缓冲区的长度
    const int emptySize = _recvBuffer->GetBuffer(pBuffer);
    // 该长度是本次操作从网络底层写入 RecvNetworkBuffer 中的数据的长度。
    const int dataSize = ::recv(_socket, pBuffer, emptySize, 0);
    if (dataSize > 0) {
      // 从底层读到 dataSize 长度的数据写入缓冲区中
      // 修改缓冲区的下标位置
      //std::cout << "recv size:" << size << std::endl;
      _recvBuffer->FillDate(dataSize);
    }
    else if (dataSize == 0) {
      //std::cout << "recv size:" << dataSize << " error:" << _sock_err() << std::endl;
      return false;
    }
    else {
      const auto socketError = _sock_err();
#ifndef MY_PLATFORM_WINDOWS
      if (socketError == EINTR || socketError == EWOULDBLOCK || socketError == EAGAIN)
        return true;
#else
      // WSAEINTR（操作被中断）  WSAEWOULDBLOCK（操作会被阻塞）
      // 在这些情况下，套接字操作被认为是成功的，只是被暂时中断或者出现了非阻塞情况，需要稍后再次尝试。
      if (socketError == WSAEINTR || socketError == WSAEWOULDBLOCK)
        return true;
#endif

      //std::cout << "recv size:" << dataSize << " error:" << socketError << std::endl;
      return false;
    }
  }
}

bool ConnectObj::HasSendData() const {
  return _sendBuffer->HasData();
}

void ConnectObj::SendPacket(Packet* pPacket) const {
  _sendBuffer->AddPacket(pPacket);
}

bool ConnectObj::Send() const {
  while (true) {
    char* pBuffer = nullptr;
    const int needSendSize = _sendBuffer->GetBuffer(pBuffer);

    // 没有数据可发送
    if (needSendSize <= 0) {
      return true;
    }

    const int size = ::send(_socket, pBuffer, needSendSize, 0);
    if (size > 0) {
      //std::cout << "send size:" << size << std::endl;
      _sendBuffer->RemoveDate(size);

      // 下一帧再发送
      if (size < needSendSize) {
        return true;
      }
    }

    if (size == -1) {
      const auto socketError = _sock_err();
      std::cout << "needSendSize:" << needSendSize << " error:" << socketError << std::endl;
      return false;
    }
  }
}
