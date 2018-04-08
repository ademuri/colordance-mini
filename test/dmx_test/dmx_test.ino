// From https://github.com/ssilverman/TeensyDMX
#include "TeensyDMX.h"

namespace teensydmx = ::qindesign::teensydmx;

teensydmx::Sender dmx{Serial2};

void setup() {
  dmx.begin();
  dmx.setPacketSize(80);
}

void loop() {
  for (int i = 1; i <= 75; i++) {
    dmx.set(i, 255);
    delay(100);
    dmx.set(i, 0); 
  }
}
