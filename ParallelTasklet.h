#ifndef ParallelTasklet_h
#define ParallelTasklet_h

#include "CollectionTasklet.h"

class ParallelTasklet : public CollectionTasklet {
  public:
    ParallelTasklet();
    void start();
    void run();
  private:
    bool isFinished;
};

#endif
