#pragma once

#include "base_buffer.h"

#pragma pack(push)
#pragma pack(4)

struct PacketHead {
  unsigned short MsgId;
};

#pragma pack(pop)

#if TestNetwork
#define DEFAULT_PACKET_BUFFER_SIZE 10
#else
// 10KB
#define DEFAULT_PACKET_BUFFER_SIZE (1024 * 10)
#endif

// 一旦生成，数据不会变，除非被重用或被销毁
class Packet : public Buffer {
  public:
    Packet();
    Packet(int msgId);
    ~Packet();

    void Dispose() override;
    void CleanBuffer();

    char* GetBuffer() const;
    void AddBuffer(const char* pBuffer, unsigned int size);
    unsigned short GetDataLength() const;
    int GetMsgId() const;
    void FillData(unsigned int size);
    void ReAllocBuffer();

  private:
    int _msgId;
};
