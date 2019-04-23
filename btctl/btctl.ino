#define BTN_A 5
#define BTN_B 6

bool buttons[30];

bool check_pressed(int btn) {
    return digitalRead(btn);
}

void setup() {
    pinMode(BTN_A, INPUT);
    pinMode(BTN_B, INPUT);
    Serial.begin(9600);

    buttons[BTN_A] = false;
    buttons[BTN_B] = false;
}

void loop() {
    if (check_pressed(BTN_A)) {
        Serial.println("(A)");
    }
    if (check_pressed(BTN_B)) {
        Serial.println("(B)");
    }
}

