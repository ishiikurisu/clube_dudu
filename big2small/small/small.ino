#define SENSOR 5
#define LED 13

void setup()
{
    pinMode(SENSOR, INPUT);
    pinMode(LED, OUTPUT);
}

void loop()
{
    digitalWrite(LED, digitalRead(SENSOR));
}
