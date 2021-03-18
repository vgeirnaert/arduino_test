#ifndef DisplayService_h
#define DisplayService_h

#include "TickableService.h"
#include "Tasklet.h"
#include "DisplayTasklet.h"

class DisplayService : public TickableService {
  public:
    DisplayService();
    void init();
    void onTick(Context context);
  private:
    Tasklet* tasklet;
    Tasklet* defaultTasklet;
    DisplayTasklet* glassTasklet;
};

#endif
