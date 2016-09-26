#define BUZZER 5
#define TAU 6.283185
const float note_a = 220.0;

void setup() {
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  tone(BUZZER, note_a, 500);
  delay(1000);
}
