#define TRANS 7
#define WAIT 500

void setup() {
  pinMode(TRANS, OUTPUT);
}

void loop() {
  digitalWrite(TRANS, HIGH);
  delay(WAIT);
  digitalWrite(TRANS, LOW);
  delay(WAIT);
}