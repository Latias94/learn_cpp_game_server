#pragma once

#include <string>
#include "network.h"

class NetworkListen : public Network {
  public:
    bool Listen(const std::string&ip, int port);
    void Update();

  protected:
    virtual int Accept();
};
