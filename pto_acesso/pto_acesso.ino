#define PULSE 3
#define ACTIVITY 2
#define LED 13

void setup()
{
    pinMode(PULSE, INPUT);
    pinMode(ACTIVITY, INPUT);
    pinMode(LED, OUTPUT);
}

void loop()
{
    bool pulse = digitalRead(PULSE);
    bool activity = digitalRead(ACTIVITY);
    bool output = LOW;

    if (pulse && !activity) {
        output = HIGH;
    }

    digitalWrite(LED, output);
}
