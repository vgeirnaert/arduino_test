#include "Arduino.h"
#include "RGBFadeTasklet.h"

#define BLUE_PIN 3
#define GREEN_PIN 5
#define RED_PIN 6

RGBFadeTasklet::RGBFadeTasklet(int pulseTimeMillis, int rainbowTimeMillis) {
  this->pulseTimeMillis = pulseTimeMillis;
  this->rainbowTimeMillis = rainbowTimeMillis;

  pinMode(BLUE_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
}

void RGBFadeTasklet::start() {
  Serial.print("starting RGBFade" );Serial.println();
  setStatus(ACTIVE);
  startTime = millis();
}

void RGBFadeTasklet::run() {
	unsigned long elapsedTime = millis() - startTime;
	RGB currentColour = getColour(elapsedTime);
	float fadeFactor = getFadeFactor(elapsedTime);

	analogWrite(RED_PIN, (int)(currentColour.r * fadeFactor));
	analogWrite(GREEN_PIN, (int)(currentColour.g * fadeFactor));
	analogWrite(BLUE_PIN, (int)(currentColour.b * fadeFactor));
}

float RGBFadeTasklet::getFadeFactor(unsigned long time) {
	if(this->pulseTimeMillis == 0) {
		return 1.0;
	}

	float fade = (float)(time % this->pulseTimeMillis) / this->pulseTimeMillis;
	float reductionFactor = max(0, fade - 0.5);
	return ((fade / 2) - reductionFactor) * 2;
}

RGB RGBFadeTasklet::getColour(unsigned long time) {
	float rainbowPercentage = (float)(time % this->rainbowTimeMillis) / this->rainbowTimeMillis;
	int colorRangeValue = rainbowPercentage * 255 * 6;

	if(rainbowPercentage < 0.16667) {
		return {255, 0, (int)colorRangeValue % 255};
	} else if(rainbowPercentage < 0.33334) {
		return {255 - ((int)colorRangeValue % 255), 0, 255};
	} else if(rainbowPercentage < 0.5) {
		return {0, (int)colorRangeValue % 255, 255};
	} else if(rainbowPercentage < 0.66667) {
		return {0, 255, 255 - ((int)colorRangeValue % 255)};
	} else if(rainbowPercentage < 0.83334) {
		return {(int)colorRangeValue % 255, 255, 0};
    } else {
    	return {255, 255 - ((int)colorRangeValue % 255, 0)};
    }
}
