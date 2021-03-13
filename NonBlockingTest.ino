#include "LightingService.h"
#include "DisplayService.h"

LightingService lightingService;
DisplayService displayService;
unsigned int currentTime = 0;

void setup() {
  Serial.begin(9600);
  lightingService.init();
  lightingService.setInterval(10);
  displayService.init();
  displayService.setInterval(10);
}

void loop() {
  currentTime = millis();
  lightingService.tick(currentTime);
  displayService.tick(currentTime);
}
