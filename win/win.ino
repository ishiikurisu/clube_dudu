#define LDR (A0)
#define LED 3

void setup() {
  pinMode(LDR, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  float light = analogRead(LDR)*5.0/1024;
  analogWrite(LED, light*512.0/5);
}
