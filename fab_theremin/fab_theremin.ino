#define BUZZ 11
#define TRIGGER 8
#define ECHO 3
#define SOUND_LIMIT 5000

// MU = 

void setup()
{
   pinMode(BUZZ, OUTPUT);
   pinMode(TRIGGER, OUTPUT);
   pinMode(ECHO, INPUT);
   Serial.begin(9600);
}

float convert (int distance)
{
    float frequency = 110;
    float mu = pow(2, 1.0/12);
    return frequency * pow(mu, distance);
}

int get_distance (int trigger, int echo)
{
    int dist;
    
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);
    dist = pulseIn(echo, HIGH)/58;
    Serial.println(dist);
    delay(100);
    
    return dist;
}

void play (float freq, int buzzer)
{
    float period = 1.0/(2 * freq);

    tone(buzzer, freq);
    /*
    digitalWrite(buzzer, HIGH);
    delay(period);
    digitalWrite(buzzer, LOW);
    delay(period);
    Serial.println(freq);
    */
}

void loop()
{
    int dist = get_distance(TRIGGER, ECHO);
    float freq = convert(dist);
    play(freq, BUZZ);
}
