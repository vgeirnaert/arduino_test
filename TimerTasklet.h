#ifndef TimerTasklet_h
#define TimerTasklet_h

#include "Tasklet.h"

class TimerTasklet : public Tasklet {
  public:
    TimerTasklet(unsigned int durationMillis);
    void start();
    void run();
  private:
    unsigned int duration;
    unsigned long startTime;
};

#endif
