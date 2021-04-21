
void setup() {

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // liga LED
  digitalWrite(LED_BUILTIN, HIGH);
  
  delay(500); //espera 500 ms
  
  // desliga LED
  digitalWrite(LED_BUILTIN, LOW);

  delay(500);  //espera 500 ms
  
}
