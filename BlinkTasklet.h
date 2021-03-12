#ifndef BlinkTasklet_h
#define BlinkTasklet_h

#include "Tasklet.h"

class BlinkTasklet : public Tasklet {
  public:
    BlinkTasklet(int timeOnMillis, int timeOffMillis);
    void start();
    void run();
  private:
    int timeOnMillis;
    int timeOffMillis;
    unsigned long startTimeMillis;
    bool isOn = false;
};

#endif
