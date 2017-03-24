#define LED 13

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  digitalWrite(LED, LOW);
}

void loop() {
}

void serialEvent() {
  String cmd = Serial.readString();

  cmd.trim();
  if (cmd.length() == 0)
    return;

  if (cmd.compareTo("high") == 0) {
    digitalWrite(LED, HIGH);
  }
  else if (cmd.compareTo("low") == 0) {
    digitalWrite(LED, LOW);
  }
  else {
    Serial.println("Inexistent command");
  }
}
