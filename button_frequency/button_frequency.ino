#define HIGHER 3
#define LOWER 2
#define BLK 13
#define STEP 50
#define CEILING 2000

volatile int delayTime = 200;

void makeHigher() {
  bool done = false;

  while (digitalRead(HIGHER))
    if (!done)
      delayTime += (delayTime < CEILING)? STEP : 0,
	  done = true;
}

void makeLower() {
  bool done = false;

  while (digitalRead(LOWER))
    if (!done)
      delayTime -= (delayTime > 0)? STEP : 0,
	  done = true;
}

void setup() {
  pinMode(HIGHER, INPUT);
  pinMode(LOWER, INPUT);
  pinMode(BLK, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(HIGHER), makeHigher, RISING);
  attachInterrupt(digitalPinToInterrupt(LOWER), makeLower, RISING);
}

void loop() {
  digitalWrite(BLK, HIGH);
  delay(delayTime/2);
  digitalWrite(BLK, LOW);
  delay(delayTime/2);
}
