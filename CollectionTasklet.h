#ifndef CollectionTasklet_h
#define CollectionTasklet_h

#include "Tasklet.h"
#include "LinkedTaskletNode.h"

class CollectionTasklet : public Tasklet {
  public:
    CollectionTasklet();
    CollectionTasklet* addTasklet(Tasklet* tasklet);
    bool hasTasklets();
    void reset();
  protected:
    LinkedTaskletNode* getFirst();
  private:
    LinkedTaskletNode* rootTaskletNode;
    LinkedTaskletNode* lastTaskletNode;
};

#endif
