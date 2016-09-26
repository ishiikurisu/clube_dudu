const int BUZZER = 3;
const int NO_BUTTONS = 3;
const int BUTTON[] = {8, 10, 12};
const float FREQ[] = {440, 587.33, 659.25};

void setup() {
  pinMode(BUZZER, OUTPUT);
  for (int i = 0; i < NO_BUTTONS; ++i)
    pinMode(BUTTON[i], INPUT);
}

void loop() {
  float freq = -1;

  for (int i = 0; i < NO_BUTTONS; ++i)
    if (digitalRead(BUTTON[i]) == HIGH)
      freq = FREQ[i];

  if (freq > 0)
    tone(BUZZER, freq, 5);
}
