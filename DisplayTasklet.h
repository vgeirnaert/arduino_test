#ifndef DisplayTasklet_h
#define DisplayTasklet_h

#include "Tasklet.h"
#include "Arduino.h"

class DisplayTasklet : public Tasklet {
  public:
    DisplayTasklet(String text, int timeMillis);
    void start();
    void run();
  private:
	String text;
	int timeMillis;
	unsigned long startTime;
};

#endif
