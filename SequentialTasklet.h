#ifndef SequentialTasklet_h
#define SequentialTasklet_h

#include "CollectionTasklet.h"

class SequentialTasklet : public CollectionTasklet {
  public:
    SequentialTasklet();
    void start();
    void run();
  private:
    bool childIsActive = false;
};

#endif
