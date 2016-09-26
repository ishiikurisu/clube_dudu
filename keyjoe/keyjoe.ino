class Key
{
    float  frequency = 110.0;
    float* function  = NULL;
    long   time      = 0;
    bool   state     = false;

    public:
    Key(float (*f)(float, float), float o)
    {
        frequency = o;
        function  = f;
        time      = 0;
        state     = false;
    }

    float noteOn(long elapsedTime)
    {
        if (!state)
        {
            state = true;
            time  = -elapsedTime;
        }

        time += elapsedTime;
        return function(frequency, time);
    }

    void noteOff()
    {
        state = false;
        time  = 0;
    }
};

const float PI  = 3.1415926;
Key   key(sine, AA0);
int   BTT   =     4;
int   SPK   =    11;
long  clock =     0;
float AA0   = 440.0;
float VCC   =   5.0;

float sine(float f, float t)
{
    return sin(2 * PI * f * t);
}

void play_note(int speaker, float note)
{
    int duty_cycle = (int) map(note, 0.0, VCC, 0, 255);
    analogWrite(speaker, duty_cycle);
}

int pressed_button(int button)
{
    return digitalRead(button);
}

void setup()
{
    pinMode(SPK, OUTPUT);
    pinMode(BTT, INPUT);
}

void loop()
{
    if (pressed_button(BTT))
    {
        clock = micros() - clock;
        play_note(SPK, key.noteOn(clock));
    }
    else
    {
        key.noteOff()
        play_note(SPK, 0);
    }

    clock = micros();
}