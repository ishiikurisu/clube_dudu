#define BLK 13
#define AIN A0

void setup() {
  int i;
  
  for (i = 0; i <= BLK; ++i)
    pinMode(i, OUTPUT);
  pinMode(AIN, INPUT);
  for (i = 0; i < BLK; ++i)
    digitalWrite(i, HIGH);
  randomSeed(analogRead(AIN));
}

void loop() {
  int waitTime = (int) random(500, 2001);
  
  digitalWrite(BLK, HIGH);
  delay(waitTime/2);
  digitalWrite(BLK, LOW);
  delay(waitTime/2);
}
