#include "CollectionTasklet.h"

#include "Arduino.h"

CollectionTasklet::CollectionTasklet() {
  rootTaskletNode = 0;
  lastTaskletNode = 0;
}

CollectionTasklet* CollectionTasklet::addTasklet(Tasklet* tasklet) {
  LinkedTaskletNode* newNode = new LinkedTaskletNode(tasklet);
  if(rootTaskletNode == 0) {
    rootTaskletNode = newNode;
  } else {
    lastTaskletNode->setNext(newNode);
  }
  lastTaskletNode = newNode;
  
  return this;
}


bool CollectionTasklet::hasTasklets() {
  return getFirst() != 0;
}

LinkedTaskletNode* CollectionTasklet::getFirst() {
  return this->rootTaskletNode;
}

void CollectionTasklet::reset() {
  Serial.print("Resetting collection");Serial.println();
  Tasklet::reset();
  LinkedTaskletNode* node = getFirst();

  while(node) {
    node->get()->reset();
    node = node->next();
  }
}
