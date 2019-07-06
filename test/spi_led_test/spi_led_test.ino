#include <FastLED.h>

const int kNumLeds = 5;
CRGB leds[kNumLeds];

const int kDataPin = 0;
const int kClockPin = 32;


void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<APA102, kDataPin, kClockPin, BGR, DATA_RATE_MHZ(1)>(leds, kNumLeds);
  FastLED.setBrightness(8);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < kNumLeds; i++) {
    leds[i] = CRGB::Red;
  }
  FastLED.show();
  delay(100);

  for (int i = 0; i < kNumLeds; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(100);
}
