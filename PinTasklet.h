#ifndef PinTasklet_h
#define PinTasklet_h

#include "Tasklet.h"

class PinTasklet : public Tasklet {
  public:
    PinTasklet(int pin, int value);
    void start();
    void run();
  private:
    int pin;
    int value;
};

#endif
