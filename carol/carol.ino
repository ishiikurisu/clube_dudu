#define BUZZER 10

void setup() {
	pinMode(BUZZER, OUTPUT);
}

void play(int freq) {
	tone(BUZZER, freq);
	delay(400);
	noTone(BUZZER);
	delay(100);
}

void loop() {
	play(262);
	play(262);
	play(349);
	play(349);
	play(392);
	play(392);
	play(349);
	play(349);
	play(349);
	play(349);
	play(330);
	play(330);
	play(294);
	play(294);
	play(262);
	play(262);
}
