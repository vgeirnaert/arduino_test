#include "SensorService.h"
#include "Arduino.h"

SensorService::SensorService() {
	distanceSensor = new HCSR04Sensor(2, 13);
}

void SensorService::init() {
	distanceSensor->init();
}

void SensorService::onTick(Context context) {
	distance = distanceSensor->getDistance();
	//Serial.println(distance);
}

float SensorService::getDistance() {
	return distance;
}