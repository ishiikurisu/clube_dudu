#define ECHO 3
#define TRIGGER 4
#define LED 5
#define ALLOWED (5.0)

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
}

/* MAIN PROCEDURES */
void setup()
{
    pinMode(ECHO, INPUT);
    pinMode(TRIGGER, OUTPUT);
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    float distance = get_distance(TRIGGER, ECHO);
    bool result = (distance <= ALLOWED) && (distance > 0);

    Serial.print("Distance: ");
    Serial.println(distance);
    alert(result);


}
