#pragma once

#include "disposable.h"
#include <map>

#ifdef MY_PLATFORM_LINUX
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define SOCKET int
#define INVALID_SOCKET -1
#define _sock_init()
#define _sock_nonblock(sockfd)                                                 \
  {                                                                            \
    int flags = fcntl(sockfd, F_GETFL, 0);                                     \
    fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);                                \
  }
#define _sock_exit()
#define _sock_err() errno
#define _sock_close(sockfd) ::close(sockfd)
#define _sock_is_blocked() (errno == EAGAIN || errno == 0)
#elif defined(MY_PLATFORM_WINDOWS)
#define FD_SETSIZE 1024

#include <Ws2tcpip.h>
#include <windows.h>
#define _sock_init()                                                           \
  {                                                                            \
    WSADATA wsaData;                                                           \
    WSAStartup(MAKEWORD(2, 2), &wsaData);                                      \
  }
#define _sock_nonblock(sockfd)                                                 \
  {                                                                            \
    unsigned long param = 1;                                                   \
    ioctlsocket(sockfd, FIONBIO, (unsigned long *)&param);                     \
  }
#define _sock_exit()                                                           \
  { WSACleanup(); }
#define _sock_err() WSAGetLastError()
#define _sock_close(sockfd) ::closesocket(sockfd)
#define _sock_is_blocked() (WSAGetLastError() == WSAEWOULDBLOCK)
#endif

class ConnectObj;

class Network : public IDisposable {
  public:
    void Dispose() override;
    bool Select();

    SOCKET GetSocket() const { return _masterSocket; }

  protected:
    static void SetSocketOpt(SOCKET socket);
    SOCKET CreateSocket();

  protected:
    // 不论是连接类还是监听类，都有一个_masterSocket
    // 连接时用来存储连接的Socket，监听时存储监听Socket
    SOCKET _masterSocket{INVALID_SOCKET};
    // 对于监听类来说，有无数个ConnectObj类，保存每个连接的数据
    // 对于连接类来说，这里只有一个ConnectObj类
    std::map<SOCKET, ConnectObj *> _connects;
    // 3个fd_set集合，分别用来存储可读、可写、异常的描述符
    fd_set readfds, writefds, exceptfds;
};
