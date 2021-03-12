#include "Arduino.h"
#include "PinTasklet.h"

PinTasklet::PinTasklet(int pin, int value) {
  this->pin = pin;
  this->value = value;

  pinMode(pin, OUTPUT);
}

void PinTasklet::start() {
  Serial.print("setting pin " );Serial.print(pin);Serial.print(" to ");Serial.print(value);Serial.println();
  setStatus(ACTIVE);
  digitalWrite(this->pin, this->value); 
  setStatus(FINISHED);
}

void PinTasklet::run() {
}
