#include "Arduino.h"
#include "BlinkTasklet.h"

BlinkTasklet::BlinkTasklet(int timeOnMillis, int timeOffMillis) {
  this->timeOnMillis = timeOnMillis;
  this->timeOffMillis = timeOffMillis;
  pinMode(LED_BUILTIN, OUTPUT);
}

void BlinkTasklet::start() {
  setStatus(ACTIVE);
  startTimeMillis = millis();
  digitalWrite(LED_BUILTIN, HIGH);
  isOn = true;
}

void BlinkTasklet::run() {
  if(getStatus() == FINISHED) {
    return;
  }
  
  if(isOn && millis() - startTimeMillis > timeOnMillis) {
    digitalWrite(LED_BUILTIN, LOW);
    isOn = false;
  }

  if(!isOn && millis() -startTimeMillis > timeOnMillis + timeOffMillis) {
    setStatus(FINISHED);
  }
}
