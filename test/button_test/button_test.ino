const int kButtonPin = 20;
const int kLedPin = 34;

void setup() {
  pinMode(kButtonPin, INPUT);
  pinMode(kLedPin, OUTPUT);
}

void loop() {
  digitalWrite(kLedPin, digitalRead(kButtonPin));
}
