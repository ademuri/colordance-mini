#include <TeensyDmx.h>

byte DMXVal[] = {50};

TeensyDmx Dmx(Serial2);

void setup() {
  Dmx.setMode(TeensyDmx::DMX_OUT);
  //Dmx.setChannels(0, DMXVal, 1);
}

void loop() {
  Dmx.setDmxChannel(4, 255);
  Dmx.setDmxChannel(5, 255);
  Dmx.loop();
}
