#include <FastLED.h>

const int kNumLeds = 1;
CRGB leds[kNumLeds];

const int kDataPin = 0;
const int kClockPin = 32;


void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<APA102, kDataPin, kClockPin>(leds, kNumLeds);
}

void loop() {
  // put your main code here, to run repeatedly:
  leds[0] = CRGB::Red;
  FastLED.show();
  delay(100);

  leds[0] = CRGB::Black;
  FastLED.show();
  delay(100);
}
