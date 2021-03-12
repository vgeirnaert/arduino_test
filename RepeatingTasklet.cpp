#include "RepeatingTasklet.h"

#include "Arduino.h"

RepeatingTasklet::RepeatingTasklet(Tasklet* tasklet, int iterations) {
  this->wrappedTasklet = tasklet;
  this->iterations = iterations;
  this->currentIteration = this->iterations;
}

void RepeatingTasklet::start() {
  Serial.print("Start repeating tasking");Serial.println();
  setStatus(ACTIVE);
  wrappedTasklet->start();
  Serial.print("Started repeating tasking");Serial.println();
}

void RepeatingTasklet::reset() {
  Serial.print("Resetting repeat tasking");Serial.println();
  Tasklet::reset();
  currentIteration = this->iterations;
  Serial.print("iterations: ");Serial.print(iterations);Serial.print(", citerations: ");Serial.print(currentIteration);Serial.println();
}

void RepeatingTasklet::run() {
  // early out if finished
  if(Tasklet::getStatus() == FINISHED) {
    return;
  }

  // check if wrapped tasklet is finished
  if(wrappedTasklet->getStatus() == FINISHED) {
    Serial.print("Wrapped task is finished");Serial.println();
    // reduce available iterations if needed (do not reduce when iterations is -1 for infinite repeats)
    if(currentIteration > 0) {
      currentIteration--;
    }

    Serial.print(currentIteration);Serial.print(" iterations to go");Serial.println();

    // we have repeated sufficient times, finish this tasklet
    if(currentIteration == 0) {
      Serial.print("We're done");Serial.println();
      setStatus(FINISHED);
      return;
    }
    
    Serial.print("Resetting wrapped task");Serial.println();
    // restart the wrapped tasklet
    wrappedTasklet->reset();
    wrappedTasklet->start();
  }

  wrappedTasklet->run();
}
