/* dudu do joe */
const int trigger = 2;
const int echo = 3;
const int juju = 4;

void setup() {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(juju, OUTPUT);
  Serial.begin(9600);
}

int distance (){
  int dist;
  
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  dist = pulseIn(echo, HIGH)/58;
  delay(100);
  return dist;
}


void loop() {
  int dist = distance();
  Serial.println(dist);
  if (dist < 10) digitalWrite(juju, HIGH);
  else digitalWrite(juju, LOW);
}
