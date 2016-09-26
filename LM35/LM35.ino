#define tempPin (A0)

void setup()
{
    pinMode(tempPin, INPUT);
    Serial.begin(9600);
}

void loop()
{
    Serial.print("TEMPERATURE = ");
    Serial.print(analogRead(tempPin) * 0.48828125);
    Serial.print("*C");
    Serial.println();
    delay(1000);
}
