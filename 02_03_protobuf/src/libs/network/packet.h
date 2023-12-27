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

    template<class ProtoClass>
    ProtoClass ParseToProto() {
      ProtoClass proto;
      proto.ParsePartialFromArray(GetBuffer(), GetDataLength());
      return proto;
    }

    template<class ProtoClass>
    void SerializeToBuffer(ProtoClass&protoClase) {
      auto total = protoClase.ByteSizeLong();
      while (GetEmptySize() < total) {
        ReAllocBuffer();
      }

      protoClase.SerializePartialToArray(GetBuffer(), total);
      FillData(total);
    }

    void Dispose() override;
    void CleanBuffer();

    char* GetBuffer() const;
    unsigned short GetDataLength() const;
    int GetMsgId() const;
    void FillData(unsigned int size);
    void ReAllocBuffer();

  private:
    int _msgId;
};
