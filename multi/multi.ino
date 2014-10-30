class Thread {
  public:
  unsigned long period;
  unsigned long last_call;

  Thread(unsigned long new_period) {
    period = new_period;
    last_call = 0;
  }

  void thread(void (*function)(void)) {
    unsigned long now = millis();

    if (now - last_call >= period) {
      last_call = now;
      function();
    }
  }
};

Thread marcie(300);
Thread bonibel(500);

void setup() {
  Serial.begin(9600);
}

void marceline() {
  Serial.println("marceline");
}

void bubblegum() {
  Serial.println("bubblegum");
}

void loop() {
  marcie.thread(marceline);
  bonibel.thread(bubblegum);
}
