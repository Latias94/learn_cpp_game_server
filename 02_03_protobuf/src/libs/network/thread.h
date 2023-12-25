#pragma once

#include "disposable.h"
#include <thread>

class Thread : public IDisposable {
  public:
    virtual bool Start();
    void Stop();
    void Dispose() override;
    virtual void Update();

    bool IsRun() const { return _isRun; }

  protected:
    bool _isRun{false};
    std::thread _thread;
};
