#ifndef SensorService_h
#define SensorService_h

#include "TickableService.h"
#include "HCSR04Sensor.h"

class SensorService : public TickableService {
  public:
    SensorService();
    void init();
    void onTick(Context context);
    float getDistance();
  private:
    HCSR04Sensor* distanceSensor;
    float distance = 0;
};

#endif
