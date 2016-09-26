#define BUZZER (3)
#define LDR (A5)

void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(LDR, INPUT);
}

void loop() {
  int light = analogRead(LDR);

  if (light < 10)
    noTone(BUZZER);
  else
    tone(BUZZER, map(light, 10, 100, 440, 880));
}
