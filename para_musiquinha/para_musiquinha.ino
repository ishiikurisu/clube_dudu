#define trigger 3
#define echo 4

void setup() {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

int distance (){
  int dist;
  
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  dist = pulseIn(echo, HIGH)/58;
  Serial.println(dist);
  delay(100);
  return dist;

}

void loop() {
  int dist;
  int t0, t;
  
  
  
}
