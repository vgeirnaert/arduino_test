#ifndef DisplayService_h
#define DisplayService_h

#include "TickableService.h"
#include "Tasklet.h"

class DisplayService : public TickableService {
  public:
    DisplayService();
    void init();
    void onTick();
  private:
    Tasklet* tasklet;
};

#endif
