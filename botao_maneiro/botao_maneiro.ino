int botao = 2;
int led = 3;
bool flag = true;

void setup() {
  Serial.begin(9600);
  pinMode (botao, INPUT);
  pinMode (led, OUTPUT);
  attachInterrupt(0, changeFlag, FALLING);
}

void changeFlag() { 
  //while (digitalRead(botao));
  flag = !flag;
}

void press_button() {
  bool fl = true;
  
  while (digitalRead(botao)) {
    if (fl) { 
      flag = !flag;
      delay(5);
    }
    fl = false;
    delay(5);
  }
}

void loop() {
  //press_button();
  digitalWrite(led, flag);
}
