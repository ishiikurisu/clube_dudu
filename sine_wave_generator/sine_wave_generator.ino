#define BUZZER 5
#define TAU 6.283185
const float pwm = 255.0;
const float note_a = 220.0 / 1000000;

float sine_wave(float freq, float time)
{
	return pwm * (sin(TAU * freq * time)/2 + 0.5);
}

void setup() {
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float past = micros();
  float now = micros();

  while (now - past < 500000) {
	float time = now - past;
    float s = sine_wave(note_a, time);
    analogWrite(BUZZER, s);
    Serial.print(time);
	Serial.print(": ");
	Serial.println(s);
    delayMicroseconds(5);
	now = micros();
  }

  Serial.println("PAUSE");
  analogWrite(BUZZER, 0);
  delay(500);
}
