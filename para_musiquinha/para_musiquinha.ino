#define trigger 2
#define echo 3
#define buzzer 4

const float freq[] = {261.63, 293.66, 329.63, 349.23, 392, 440, 493.88};
char music1[] = {'C', 'D', 'E', 'F', 'X', 'F', 'F', 'X'};
char music2[] = {'C', 'D', 'C', 'D', 'X', 'D', 'D', 'X'};
char music3[] = {'C', 'G', 'F', 'E', 'X', 'E', 'E', 'X'};
int tempo = 250;

float note (char letter) {
  switch (letter) {
    case 'C':
      tone(buzzer, freq[0]);
      break;
    case 'D':
      tone(buzzer, freq[1]);
      break;
    case 'E':
      tone(buzzer, freq[2]);
      break; freq[2];
    case 'F':
      tone(buzzer, freq[3]);
      break;
    case 'G':
      tone(buzzer, freq[4]);
      break;
    case 'A':
      tone(buzzer, freq[5]);
      break;
    case 'B':
      tone(buzzer, freq[6]);
      break;
    default:
      noTone(buzzer);
  }
}

void setup() {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
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
  int i;
  
  for (i = 0; i < 8; ++i) {
    note(music1[i]);
    delay(tempo);
    noTone(buzzer);
    while (distance() < 10);
  }
  for (i = 0; i < 8; ++i) {
    note(music2[i]);
    delay(tempo);
    noTone(buzzer);
    while (distance() < 10);
  }
  for (i = 0; i < 8; ++i) {
    note(music3[i]);
    delay(tempo);
    noTone(buzzer);
    while (distance() < 10);
  }
  for (i = 0; i < 8; ++i) {
    note(music1[i]);
    delay(tempo);
    noTone(buzzer);
    while (distance() < 10);
  }
}
