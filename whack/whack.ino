/* GAME STUFF */
const int INLETS[] = { 2, 3 };
const int OUTLETS[] = { 8, 9 };
const int NO_MOLES = 2;
int POINTS = 0;

/* HARDWARE STUFF */
unsigned long ACC_TIME = 0;
const unsigned long CLOCK_STEP = 300;
const int CLOCK_TICKS = 4;
int CLOCK_TICK = 0;

void tick_clock(unsigned long time_ellapsed)
{
    ACC_TIME += time_ellapsed;
    if (ACC_TIME >= CLOCK_STEP)
    {
        CLOCK_TICK = (CLOCK_TICK + 1) % CLOCK_TICKS;
        ACC_TIME = 0;
    }
}

bool button_pressed(int button)
{
    bool pressed = false;

    if (digitalRead(button) == HIGH) {
        delay(10);
        pressed = true;
    }

    return pressed;
}

/* MOLE STUFF */
bool ALIVE = false;
bool SHOULD_SHOW = false;
int CURRENT_MOLE = 0;

int choose_mole(int no_moles)
{
    return (int) random(0, no_moles);
}

void try_to_kill()
{
    if (button_pressed(INLETS[CURRENT_MOLE])) {
        ALIVE = false;
        POINTS++;
    }
}

void show_mole()
{
    if (ALIVE) {
        digitalWrite(OUTLETS[CURRENT_MOLE], HIGH);
        delay(10);
        try_to_kill();
    }
    else {
        digitalWrite(OUTLETS[CURRENT_MOLE], LOW);
    }
}

void hide_mole()
{
    int i;

    for (i = 0; i < NO_MOLES; ++i)
    {
        digitalWrite(OUTLETS[i], LOW);
    }

    CURRENT_MOLE = choose_mole(NO_MOLES);
    ALIVE = true;
}

/* INFO PROCEDURES */
void display_info()
{
    Serial.print("PTS:");
    Serial.print(POINTS);
    // Serial.print(" CLK:");
    // Serial.print(CLOCK_TICK);
    Serial.println(" WHACK");
}

/* MAIN PROCEDURES */
void setup()
{
    int i;

    for (i = 0; i < NO_MOLES; ++i)
    {
        pinMode(INLETS[i], INPUT);
        pinMode(OUTLETS[i], OUTPUT);
    }

    POINTS = 0;
    ACC_TIME = 0;
    Serial.begin(9600);
}

void loop()
{
    unsigned long now = millis();

    switch (CLOCK_TICK) {
        case 0:
        case 1:
        case 2:
            show_mole();
            break;

        case 3:
            hide_mole();
            break;

    }

    delay(10);
    tick_clock(millis() - now);
    display_info();
}
