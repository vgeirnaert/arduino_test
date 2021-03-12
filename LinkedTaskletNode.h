#ifndef LinkedTaskletNode_h
#define LinkedTaskletNode_h

#include "Tasklet.h"

class LinkedTaskletNode {
  public:
    LinkedTaskletNode(Tasklet* tasklet);
    Tasklet* get();
    bool hasNext();
    LinkedTaskletNode* next();
    void setNext(LinkedTaskletNode* node);
  private:
    Tasklet* tasklet;
    LinkedTaskletNode* nextNode;
};

#endif
