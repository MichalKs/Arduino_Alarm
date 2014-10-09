/*
 * main.cpp
 *
 *  Created on: 3 paź 2014
 *      Author: mik
 */


#include <Arduino.h>
#include <Servo.h>

static const uint8_t ledPin =  13;    // LED connected to digital pin 13
static const uint8_t magneticSwitch = 2; // Magnetic contact switch
static const uint8_t relay = 3; // relay for alarm signal

void setup(void)   {

  pinMode(ledPin, OUTPUT); // initialize the digital pin as an output
  pinMode(magneticSwitch, INPUT);
  pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH); // turn of relay

  digitalWrite(magneticSwitch, HIGH); // pull-up resistor
  Serial.begin(115200);
}

void loop(void) {

  digitalWrite(ledPin, HIGH);   // set the LED on
  delay(100);                   // delay
  digitalWrite(ledPin, LOW);    // set the LED off
  delay(100);                   // delay

  if (digitalRead(magneticSwitch)) {
    Serial.println("Door unlocked");
    digitalWrite(relay, LOW); // turn on alarm

    // add sending SMS here

    delay(3000); // delay the alarm
  } else {
    Serial.println("Door locked");
    digitalWrite(relay, HIGH); // turn off alarm
  }

}


int main(void) {

  /* Must call init for arduino to work properly */
  init();
  setup();

  while (true) {
	  loop();
  }

}
