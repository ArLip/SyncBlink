// Blinks a byte from 128 to 255, followed by fixed 149.
// So patterned blinked always starts with a 1 (HIGH),
// 149 is bounded asymmetric pattern (10010101)
#define timingPin 13
#define triggerPin 8

#define TON 100 // time pulse is HIGH if on
#define TOFF 100 // time between pulses
#define PAUSE 300 // time between Bytes

byte counter = 128;

void setup() {
  pinMode(timingPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for (byte counter = 128; counter < 255; counter++) {
    flash(counter);
    flash(149);
  }
}

void flash(byte counter) {
  //Serial.print(counter);
  //Serial.print(": ");
  for (int n = 7; n >= 0; n--) {
    digitalWrite(timingPin, (counter >> n) & 0x1);
    //Serial.print((counter >> n) & 0x1);
    delay(TON);
    digitalWrite(timingPin, LOW);
    delay(TOFF);
  }
  //Serial.println("\n=============");
  delay(PAUSE);
}
