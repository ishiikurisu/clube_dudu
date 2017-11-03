#define LED_LOW 10
#define LED_MID 9
#define LED_HI 8
#define LDR (A0)

int mv;
bool low, mid, high;

void setup()
{
    pinMode(LDR, INPUT);
    pinMode(LED_LOW, OUTPUT);
    pinMode(LED_MID, OUTPUT);
    pinMode(LED_HI, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    mv = map(analogRead(LDR), 0, 1024, 0, 5000);
    low = mv > 500;
    mid = mv > 1667;
    high = mv > 3334;
    digitalWrite(LED_LOW, low);
    digitalWrite(LED_MID, mid);
    digitalWrite(LED_HI, high);
}
