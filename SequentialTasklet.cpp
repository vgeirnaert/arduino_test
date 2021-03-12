#include "SequentialTasklet.h"

#include "Arduino.h"

SequentialTasklet::SequentialTasklet() {
}

void SequentialTasklet::start() {
  // early out if no tasklets are included
  if(!hasTasklets()) {
    setStatus(FINISHED);
    return;
  }

  Serial.print("Starting sequence");Serial.println();
  
  setStatus(ACTIVE);
  getFirst()->get()->start();
  Serial.print("Started sequence");Serial.println();
}

void SequentialTasklet::run() {
    // early out if no tasklets are included
  if(!hasTasklets()) {
    setStatus(FINISHED);
    return;
  }

  LinkedTaskletNode* node = getFirst();
  childIsActive = false;
  while(node) {
    if(node->get()->getStatus() != FINISHED) {
      childIsActive = true;
      if(node->get()->getStatus() == PENDING) {
        node->get()->start();
      }
      node->get()->run();
      break;
    }

    node = node->next();
  }

  if(!childIsActive) {
    Serial.print("Ending sequence");Serial.println();
    setStatus(FINISHED);
  }
}
