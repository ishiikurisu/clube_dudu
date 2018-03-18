#define AC 3

void setup()
{
    pinMode(AC, OUTPUT);
}

void loop()
{
    int v;

    for (v = 0; v < 256; v += 10)
    {
        analogWrite(AC, v);
        delay(100);
    }

    for (v = 255; v >= 0; v -= 10)
    {
        analogWrite(AC, v);
        delay(100);
    }
}
