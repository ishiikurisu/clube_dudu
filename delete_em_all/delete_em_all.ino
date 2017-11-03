#define BUT_A 5
#define BUT_B 6
#define BUT_C 7
#define LED_A 8
#define LED_B 9
#define LED_C 10

bool A = true;
bool B = false;
bool C = false;
bool callback_A = false;
bool callback_B = false;
bool callback_C = false;

/*******
 * I/O *
 *******/

void listen()
{
    static bool state_a = false;
    static bool state_b = false;
    static bool state_c = false;
    bool pressed_a = digitalRead(BUT_A);
    bool pressed_b = digitalRead(BUT_B);
    bool pressed_c = digitalRead(BUT_C);

    if (pressed_a) {
        if (state_a) {

        } else {
            state_a = true;
        }
        delay(10);
    } else {
        if (state_a) {
            callback_A = true;
        }
        state_a = false;
    }

    if (pressed_b) {
        if (state_b) {

        } else {
            state_b = true;
        }
        delay(10);
    } else {
        if (state_b) {
            callback_B = true;
        }
        state_b = false;
    }

    if (pressed_c) {
        if (state_c) {

        } else {
            state_c = true;
        }
        delay(10);
    } else {
        if (state_c) {
            callback_C = true;
        }
        state_c = false;
    }
}

void think()
{
    if (callback_A) {
        B = !B;
        C = !C;
        callback_A = false;
    }

    if (callback_B) {
        A = !A;
        C = !C;
        callback_B = false;
    }

    if (callback_C) {
        A = !A;
        B = !B;
        callback_C = false;
    }
}

void speak()
{
    digitalWrite(LED_A, A);
    digitalWrite(LED_B, B);
    digitalWrite(LED_C, C);
}

/*******************
 * MAIN PROCEDURES *
 *******************/
void setup()
{
    pinMode(BUT_A, INPUT);
    pinMode(BUT_B, INPUT);
    pinMode(BUT_C, INPUT);
    pinMode(LED_A, OUTPUT);
    pinMode(LED_B, OUTPUT);
    pinMode(LED_C, OUTPUT);
}

void loop()
{
    listen();
    think();
    speak();
}
