#include "Arduino.h"
#include "TimerTasklet.h"

TimerTasklet::TimerTasklet(unsigned int durationMillis) {
  duration = durationMillis;
}

void TimerTasklet::start() {
  setStatus(ACTIVE);
  startTime = millis();
}

void TimerTasklet::run() {
  if(Tasklet::getStatus() == ACTIVE && millis() - startTime > duration) {
    Serial.print("waited " );Serial.print(duration);Serial.print(" millis");Serial.println();
    setStatus(FINISHED);
  }
}
