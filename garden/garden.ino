#define PLANT (A0)
#define BATTERY 2
#define WATER_NEEDED 13

float to_volts(int pwm) {
	return map(pwm, 0, 1024, 0.0, 5.0);
}

bool needs_water(int plant) {
	bool result = false;

	if (to_volts(plant) > to_volts(300)) {
		result = true;
	}

	return result;
}

void setup() {
	pinMode(PLANT, INPUT);
	pinMode(WATER_NEEDED, OUTPUT);
	pinMode(BATTERY, INPUT);

	digitalWrite(BATTERY, HIGH);
	Serial.begin(9600);
}

void loop() {
	int plant_voltage;

	plant_voltage = analogRead(PLANT);

	Serial.println(plant_voltage);
	if (needs_water(plant_voltage)) {
		digitalWrite(WATER_NEEDED, HIGH);
	}
	else {
		digitalWrite(WATER_NEEDED, LOW);
	}
}
