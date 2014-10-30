/* dudu da lulu */
const int box = 3;
const int porta = 2;
const float freq[] = {261.63, 293.66, 329.63, 349.23, 392, 440, 493.88};
char music1[] = {'C', 'C', 'F', 'F', 'G', 'G', 'F', 'X'};
char music2[] = {'F', 'F', 'E', 'E', 'D', 'D', 'C', 'X'};
char music3[] = {'C', 'G', 'F', 'E', 'X', 'E', 'E', 'X'};
int tempo = 250;

float note (char letter) {
  switch (letter) {
    case 'C':
      return freq[0];
    case 'D':
      return freq[1];
    case 'E':
      return freq[2];
    case 'F':
      return freq[3];
    case 'G':
      return freq[4];
    case 'A':
      return freq[5];
    case 'B':
      return freq[6];
    case 'X':
      return -1;
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(box, OUTPUT);
  pinMode (porta, INPUT);
}

void loop() {
  int i, j;
  
  if(digitalRead(porta))
  {
  
    for (i = 0; i < 8; ++i) {
      tone(box, note(music1[i]));
      delay(tempo);
    }
    for (i = 0; i < 8; ++i) {
      tone(box, note(music2[i]));
      delay(tempo);
    }
    for (i = 0; i < 8; ++i) {
      tone(box, note(music3[i]));
      delay(tempo);
    }
    for (i = 0; i < 8; ++i) {
      tone(box, note(music1[i]));
      delay(tempo);
    }
  }
}

