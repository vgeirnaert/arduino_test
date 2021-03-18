#include "HCSR04Sensor.h"
#include "Arduino.h"

HCSR04Sensor::HCSR04Sensor(int pinTrigger, int pinEcho) {
	this->pinTrigger = pinTrigger;
	this->pinEcho = pinEcho;
}

void HCSR04Sensor::init() {
	pinMode(this->pinEcho, INPUT);
	pinMode(this->pinTrigger, OUTPUT);
}

float HCSR04Sensor::getDistance() {
	digitalWrite(this->pinTrigger, LOW);
	delayMicroseconds(2);
	digitalWrite(this->pinTrigger, HIGH);
	delayMicroseconds(10);
	digitalWrite(this->pinTrigger, LOW);
	delayMicroseconds(2);
	noInterrupts();
	unsigned long duration = pulseIn(this->pinEcho, HIGH, 10000);
	interrupts();
	return duration / 58.0;
}