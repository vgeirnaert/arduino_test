#include "Arduino.h"
#include "BlinkTasklet.h"

BlinkTasklet::BlinkTasklet(int timeOnMillis, int timeOffMillis) {
  this->timeOnMillis = timeOnMillis;
  this->timeOffMillis = timeOffMillis;
  pinMode(13, OUTPUT);
}

void BlinkTasklet::start() {
  setStatus(ACTIVE);
  startTimeMillis = millis();
  digitalWrite(13, HIGH);
  isOn = true;
}

void BlinkTasklet::run() {
  if(getStatus() == FINISHED) {
    return;
  }
  
  if(isOn && millis() - startTimeMillis > timeOnMillis) {
    digitalWrite(13, LOW);
    isOn = false;
  }

  if(!isOn && millis() -startTimeMillis > timeOnMillis + timeOffMillis) {
    setStatus(FINISHED);
  }
}
