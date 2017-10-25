#define PULSE 3
#define ACTIVITY 2
#define LED 13
#define STANDBY 1
#define DIALING 2
#define DIALED 4
#define SIZE 6

/* #######
   # I/O #
   ####### */

bool generated_input = false;
int dialed_number = -1;
int* password;

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
                delay(10);
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
    static int pos = 0;

    if ((generated_input) && (dialed_number > 0)) {
        dialed_number = (dialed_number == 10)? 0 : dialed_number;

        Serial.print("You dialed ");
        Serial.println(dialed_number);
        if (dialed_number == password[pos]) {
            pos++;
            if (pos == SIZE) {
                pos = 0;
                Serial.println("Password correct!");
                delay(100);
            }
        }
        else {
            pos = 0;
            Serial.println("Try again!");
            delay(100);
        }

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
    pinMode(A0, INPUT);
    Serial.begin(9600);

    password = (int*) malloc(sizeof(int) * SIZE);
    randomSeed(analogRead(A0));
    for (int i = 0; i < SIZE; ++i)
    {
        password[i] = (int) random(0, 10);
        Serial.print(password[i]);
    }
    Serial.println(";");
}

void loop()
{
    readInput();
    writeOutput();
}
