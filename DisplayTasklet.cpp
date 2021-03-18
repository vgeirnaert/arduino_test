#include "DisplayTasklet.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

DisplayTasklet::DisplayTasklet(String text, int timeMillis) {
	this->text = text;
	this->timeMillis = timeMillis;
}

DisplayTasklet::~DisplayTasklet() {
	lcd.begin(16, 2);
}

void DisplayTasklet::start() {
	setStatus(ACTIVE);
	write();
    startTime = millis();
}

void DisplayTasklet::run() {
	if(millis() - startTime > timeMillis) {
		lcd.clear();
		setStatus(FINISHED);
	}
}

void DisplayTasklet::setText(String text) {
	this->text = text;
	write();
}

void DisplayTasklet::write() {
	lcd.clear();
	lcd.setCursor(0, 0);
    lcd.print(text);
    Serial.print(text);Serial.println();
}