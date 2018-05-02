// From https://github.com/ssilverman/TeensyDMX
#include "TeensyDMX.h"
#include <Encoder.h>

Encoder enc(8, 9);

namespace teensydmx = ::qindesign::teensydmx;

const int potPin = A3;
const int tempoLedPin = 35;
const int onboardLedPin = 13;
const int tempoButtonPin = 39;

teensydmx::Sender dmx{Serial2};

void setup() {
  dmx.begin();
  dmx.setPacketSize(80);

  pinMode(potPin, INPUT);
  pinMode(tempoLedPin, OUTPUT);
  pinMode(tempoButtonPin, INPUT_PULLUP);
  pinMode(onboardLedPin, OUTPUT);
  /*for (int i = 1; i < 80; i++) {
    dmx.set(i, 0);
  }*/
}

void loop() {
  /*for (int i = 1; i <= 75; i++) {
    dmx.set(i, 255);
    delay(100);
    dmx.set(i, 0); 
  }*/
  //dmx.set(1, 11);
  //dmx.set(2, 59);
  //dmx.set(3, 255);
  dmx.set(4, 255);
  dmx.set(5, enc.read() % 256);
  dmx.set(6, analogRead(potPin) >> 2);
  //dmx.set(7, 255);
  //dmx.set(6, 255);

  digitalWrite(onboardLedPin, digitalRead(tempoButtonPin));
  
  delay(10);
}
