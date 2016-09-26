class Key
{
    float time = 0.0;
    float frequency = 0.0;
    float period = 0.0;
    float (*wave)(float);

    public:
    Key(float (*function)(float), float freq)
    {
        time = 0.0;
        frequency = freq;
        period = 1 / freq;
        wave = function;
    }

    float play(float moment)
    {
        return wave(moment * frequency);
    }
};

float sine(float t)
{ return (float) sin(2 * 3.14 * t); }

Key key(sine, 55.0);
int speaker = 11;

void setup()
{
    pinMode(speaker, OUTPUT);
}

void loop()
{
    float mag = 256 * key.play(millis() / 1000.0);
    int pwr = map(mag, -255, 255, 0, 255);
    analogWrite(speaker, pwr);
}

