int botao = 2;
int led = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode (botao, INPUT);
  pinMode (led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(digitalRead(botao) == HIGH)
  {
  digitalWrite(led, true);
  }
  digitalWrite(led, LOW);
}
