#include "LinkedTaskletNode.h"

LinkedTaskletNode::LinkedTaskletNode(Tasklet* tasklet) {
  this->tasklet = tasklet;
  this->nextNode = 0;
}

Tasklet* LinkedTaskletNode::get() {
  return this->tasklet;
}

bool LinkedTaskletNode::hasNext() {
  return this->nextNode != 0;
}

LinkedTaskletNode* LinkedTaskletNode::next() {
  return this->nextNode;
}

void LinkedTaskletNode::setNext(LinkedTaskletNode* next) {
  this->nextNode = next;
}
