#define ECHO 3
#define TRIGGER 12
#define FEED 11
#define LED 13
#define ALLOWED (10.0)

/* CALCULATIONS */

float get_distance (int trigger, int echo)
{
    float dist;

    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);
    dist = pulseIn(echo, HIGH)/58.0;
    delay(100);

    return dist;
}

void alert(bool what)
{
    digitalWrite(LED, what);
    digitalWrite(FEED, HIGH);
}

/* MAIN PROCEDURES */
void setup()
{
    pinMode(ECHO, INPUT);
    pinMode(TRIGGER, OUTPUT);
    pinMode(LED, OUTPUT);
    pinMode(FEED, OUTPUT);
}

void loop()
{
    float distance = get_distance(TRIGGER, ECHO);
    bool result = (distance <= ALLOWED) && (distance > 0);
    alert(result);
}
