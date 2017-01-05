#define TRIGGER (2)
#define ECHO (3)
#define LDR (A0)
#define LIGHT (5)

const int APPROPRIATE_TIME = 5000; // millis
const float APPROPRIATE_DISTANCE = 30.0; // centimeters
const float APPROPRIATE_LIGHT = 4.0; // volts

float get_distance (int trigger, int echo)
{
    float dist;

    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);
    dist = pulseIn(echo, HIGH)/58.0;
    delay(100);

    return dist;
}

// Using a distance sensor
bool there_is_motion() {
  float distance = get_distance(TRIGGER, ECHO);
  Serial.print("DIST: ");
  Serial.println(distance);
  return distance < APPROPRIATE_DISTANCE;
}

// Less light means more voltage
bool there_is_light() {
  int pwm = analogRead(LDR);
  float volt = map((float) pwm, 0, 1024, 0, 5000) / 1000.0;
  Serial.print("VOLT: ");
  Serial.println(volt);
  return volt < APPROPRIATE_LIGHT;
}

// Triggers the washroom light
void light(bool bang) {
  digitalWrite(LIGHT, bang);
}

/* ARDUINO SETUP FUNCTION */
void setup() {
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LDR, INPUT);
  pinMode(LIGHT, OUTPUT);
  Serial.begin(9600);
}

/* ARDUINO LOOP FUNCTION */
void loop() {
  bool is_motion = there_is_motion();
  bool is_light = there_is_light();

  if (is_motion && !is_light) {
    light(true);
    delay(APPROPRIATE_TIME);
  } else {
    light(false);
  }
}
