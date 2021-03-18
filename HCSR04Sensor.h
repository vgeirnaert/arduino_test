#ifndef HCSR04Sensor_h
#define HCSR04Sensor_h

class HCSR04Sensor {
  public:
    HCSR04Sensor(int pinTrigger, int pinEcho);
    void init();
	float getDistance();
  private:
    int pinTrigger;
    int pinEcho;
};

#endif
