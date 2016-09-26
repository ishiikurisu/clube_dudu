/*
# Light dependent resistor

When the light level is high, the LDR's resistence
is low; therefore there is more current flowing
throught the circuit

*/

#define LED (3)
#define LDR (A5)

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(LDR, INPUT);
  Serial.begin(9600);
}

void loop() {
  int light = analogRead(LDR);
  analogWrite(LED, light);
  Serial.println(light);
}
