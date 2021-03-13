#include "DisplayTasklet.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

DisplayTasklet::DisplayTasklet(String text, int timeMillis) {
	this->text = text;
	this->timeMillis = timeMillis;
}

void DisplayTasklet::start() {
	setStatus(ACTIVE);
	lcd.begin(16, 2);
	lcd.setCursor(0, 0);
    lcd.print(text);
    startTime = millis();
    Serial.print(text);Serial.println();
}

void DisplayTasklet::run() {
	if(millis() - startTime > timeMillis) {
		lcd.clear();
		setStatus(FINISHED);
	}
}