#define LM35 (A0)
#define LDR (A1)

float temperature;
float light;

void setup()
{
    pinMode(LM35, INPUT);
    pinMode(LDR, INPUT);
    Serial.begin(9600);
}

void loop()
{
    temperature = (4 * analogRead(LM35) * 100.0) / 1024;
    light = map(analogRead(LDR), 0, 1024, 0, 5000) / 1000.0;
    Serial.print(temperature);
    Serial.print(" oC\t");
    Serial.print(light);
    Serial.println(" lms");
}
