#include "network.h"

void Network::Dispose() {
  auto iter = _connects.begin();
  while (iter != _connects.end()) {
    auto connect = *iter;
    connect->Dispose();
    delete connect;
    iter = _connects.erase(iter);
  }
}
