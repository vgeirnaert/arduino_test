#ifndef TickableService_h
#define TickableService_h

#include "Structs.h"

class TickableService {
  public:
    void setInterval(unsigned int tickIntervalMillis);
    void tick(Context context);
    virtual void onTick(Context context);
  private:
    unsigned int interval;
    unsigned long previousTickMillis = 0;
};

#endif
