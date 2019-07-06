#include <SPI.h>


const int kNumLeds = 5;

const int kDataPin = 0;
const int kClockPin = 32;


void setup() {
   SPI1.setMOSI(0);
   SPI1.setSCK(32);
}

void setLeds(char brightness) {
  SPI1.begin();
  SPI1.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
  SPI1.transfer(0);
  SPI1.transfer(0);
  SPI1.transfer(0);
  SPI1.transfer(0);

  for (int i = 0; i < 5; i++) {
    SPI1.transfer(0xFF);
    SPI1.transfer(brightness);
    SPI1.transfer(0x00);
    SPI1.transfer(0x00);
  }
  
  SPI1.transfer(0);
  SPI1.transfer(0);
  SPI1.transfer(0);
  SPI1.transfer(0);
  SPI1.transfer(0);
  SPI1.endTransaction();
  SPI1.end();
}

void loop() {
  for (char i = 0; i < 255; i++) {
    setLeds(i);
    delay(10);
  }
  for (char i = 255; i > 0; i--) {
    setLeds(i);
    delay(10);
  }
  
}
