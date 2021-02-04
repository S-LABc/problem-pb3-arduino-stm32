#define LED PC13
#define BTN PB3

boolean btn_state = false;

void setup() {
                          // rogerclarkmelbourne https://github.com/rogerclarkmelbourne/Arduino_STM32
  enableDebugPorts();     // Отключает JTAG, оставляет SWD
  //disableDebugPorts();    // Отключает JTAG и SWD
  
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);
  digitalWrite(LED, HIGH);
}

void loop() {
  if (!btn_state && digitalRead(BTN) == LOW) {
    digitalWrite(LED, LOW);
    btn_state = true;
  }
  if (btn_state && digitalRead(BTN) == HIGH) {
    digitalWrite(LED, HIGH);
    btn_state = false;
  }
}
