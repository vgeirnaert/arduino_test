#ifndef RBGFade_h
#define RBGFade_h

#include "Tasklet.h"

struct RGB {
	byte r;
	byte g;
	byte b;
};

class RGBFade : public Tasklet {
  public:
    RGBFade(int pulseTimeMillis, int rainbowTimeMillis);
    void start();
    void run();
  private:
    int pulseTimeMillis;
    int rainbowTimeMillis;
    unsigned long startTime;

    float getFadeFactor(unsigned long time);
    RGB getColour(unsigned long time);
};

#endif
