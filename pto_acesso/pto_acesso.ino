#define PULSE 3
#define ACTIVITY 2
#define LED 13
#define STANDBY 1
#define DIALING 2
#define DIALED 4

/* #######
   # I/O #
   ####### */

bool generated_input = false;
int dialed_number = -1;

void readInput()
{
    static int state = STANDBY;
    bool pulse = digitalRead(PULSE);
    bool activity = digitalRead(ACTIVITY);

    switch (state)
    {
        case STANDBY:
            if (pulse == HIGH) {
                state = DIALING;
                dialed_number = 0;
            }
        break;

        case DIALING:
            if (pulse == LOW) {
                state = STANDBY;
                generated_input = true;
            }
            else if (activity == LOW) {
                state = DIALED;
                dialed_number++;
            }
        break;

        case DIALED:
            if (activity == HIGH) {
                state = DIALING;
            }
        break;
    }
}

void writeOutput()
{
    if ((generated_input) && (dialed_number > 0)) {
        dialed_number = (dialed_number == 10)? 0 : dialed_number;
        Serial.print("You dialed ");
        Serial.println(dialed_number);
        generated_input = false;
        dialed_number = -1;
    }
}

/* ###################
   # MAIN PROCEDURES #
   ################### */

void setup()
{
    pinMode(PULSE, INPUT);
    pinMode(ACTIVITY, INPUT);
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    readInput();
    writeOutput();
}
