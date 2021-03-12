#include "ParallelTasklet.h"
#include "Arduino.h"

ParallelTasklet::ParallelTasklet(){
}

void ParallelTasklet::start() {
  Serial.print("Starting parallel tasks");Serial.println();
  setStatus(ACTIVE);
  isFinished = false;
  LinkedTaskletNode* node = getFirst();
  while(node) {
    if(node->get()->getStatus() == PENDING) {
      node->get()->start();
    }
    node = node->next();
  }
}

void ParallelTasklet::run() {
  isFinished = true;
  LinkedTaskletNode* node = getFirst();
  while(node) {
    if(node->get()->getStatus() == ACTIVE) {
      node->get()->run();
      isFinished = false;
    }

    node = node->next();
  }

  if(isFinished) {
    Serial.print("Finished parallel tasks");Serial.println();
    setStatus(FINISHED);
  }
}
