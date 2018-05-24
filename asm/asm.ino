#define LED 13

void asm_delay(uint8_t ms)
{
  uint16_t cnt, delay_count;
  asm volatile (
    "\n"
    "L_dl1%=:" "\n\t"
    "mov %A0, %A2" "\n\t"
    "mov %B0, %B2" "\n"
    "L_dl2%=:" "\n\t"
    "sbiw %A0, 1" "\n\t"
    "brne L_dl2%=" "\n\t"
    "dec %1" "\n\t"
    "brne L_dl1%=" "\n\t"
    : "=&w" (cnt)
    : "r" (ms), "r" (delay_count)
  );
}

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LED, HIGH);
  asm_delay(500);
  digitalWrite(LED, LOW);
  asm_delay(500);
}
