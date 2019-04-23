#define ENGINE 13

void setup()
{
    pinMode(ENGINE, OUTPUT);
}

void loop()
{
    digitalWrite(ENGINE, HIGH);
    delay(150);
    digitalWrite(ENGINE, LOW);
    delay(50);
}
