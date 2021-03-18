#include "LightingService.h"
#include "DisplayService.h"
#include "SensorService.h"
#include "Structs.h"

LightingService lightingService;
DisplayService displayService;
SensorService sensorService;
unsigned int currentTime = 0;

void setup() {
  Serial.begin(9600);
  lightingService.init();
  lightingService.setInterval(10);
  displayService.init();
  displayService.setInterval(10);
  sensorService.init();
  sensorService.setInterval(10);
}

void loop() {
  currentTime = millis();
  float distance = sensorService.getDistance();
  Context alfredContext = {currentTime, {distance, distance > 0}};
  sensorService.tick(alfredContext);
  lightingService.tick(alfredContext);
  displayService.tick(alfredContext);
}
