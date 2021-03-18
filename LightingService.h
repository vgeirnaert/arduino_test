#ifndef LightingService_h
#define LightingService_h

#include "TickableService.h"
#include "Tasklet.h"

class LightingService : public TickableService {
  public:
    LightingService();
    void init();
    void onTick(Context context);
  private:
    Tasklet* lightingTasklet;
};

#endif
