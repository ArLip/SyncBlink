#define timingPin 13
#define triggerPin 8

#define TON 100
#define TOFF 100
#define PAUSE 300

byte counter = 128;

void setup() {
  // put your setup code here, to run once:
  pinMode(timingPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
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
