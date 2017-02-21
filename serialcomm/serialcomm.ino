void setup() {
  Serial.begin(9600);
}

void loop() {
}

void serialEvent() {
  String cmd = Serial.readString();
  Serial.print("Received: ");
  Serial.println(cmd);
}
