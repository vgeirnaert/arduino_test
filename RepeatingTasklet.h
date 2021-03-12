#ifndef RepeatingTasklet_h
#define RepeatingTasklet_h

#include "Tasklet.h"

class RepeatingTasklet : public Tasklet {
  public:
    RepeatingTasklet(Tasklet* tasklet, int iterations); // pass -1 for infinite iterations
    void start();
    void reset();
    void run();
  private:
    Tasklet* wrappedTasklet;
    int iterations;
    int currentIteration;
};

#endif
