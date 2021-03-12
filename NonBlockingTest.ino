#include "LightingService.h"

LightingService lightingService;
unsigned int currentTime = 0;

void setup() {
  Serial.begin(9600);
  lightingService.init();
  lightingService.setInterval(10);
}

void loop() {
  currentTime = millis();
  lightingService.tick(currentTime);
}
