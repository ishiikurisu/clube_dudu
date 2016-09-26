#include <Servo.h>
#define SERVO_OUTPUT 9
#define EYES_TRIGGER 8
#define EYES_ECHO 3
#define FAN_SPEED 5

Servo servo;
bool key = false;

/* hardware interfaces */
int get_distance(int trigger, int echo)
{
    int dist;

    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);
    dist = pulseIn(echo, HIGH)/58;
    Serial.println(dist);
    delay(50);

    return dist;
}

void walk_servo() {
  static int angle = 0;

  servo.write(angle);
  angle = (angle+FAN_SPEED) % 180;
}

/* software interfaces */
bool activate_switch() {
  int distance = get_distance(EYES_TRIGGER, EYES_ECHO);
  static bool memo = false;
  bool result = (distance < 5)? true : false;

  if (result == true && memo == true)
    result = false;
  else if (result == true && memo == false)
    memo = true;
  delay(5);

  return result;
}

void update_servo(bool flag) {
  if (flag) walk_servo();
}

/* main functions */
void setup() {
  pinMode(EYES_TRIGGER, OUTPUT);
  pinMode(EYES_ECHO, INPUT);
  servo.attach(SERVO_OUTPUT);
  Serial.begin(9600);
}

void loop() {
  key = (activate_switch())? !key : key;
  update_servo(key);
}
