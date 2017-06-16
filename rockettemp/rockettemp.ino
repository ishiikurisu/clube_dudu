#define LM35 (A0)

float temperature;

void setup()
{
    pinMode(LM35, INPUT);
    Serial.begin(9600);
}

void loop()
{
    temperature = (4 * analogRead(LM35) * 100.0) / 1024;
    Serial.print(temperature);
    Serial.println(" oC");
}
