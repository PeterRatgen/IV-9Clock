void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  
  for(int i = 0; i < 14; i++)
    pinMode(i, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
    for(int i = 0; i < 14; i++){
      digitalWrite(i, HIGH);   // turn the LED on (HIGH is the voltage level)
    }
  delay(2000);
  for(int i = 0; i < 14; i++){
    digitalWrite(i, LOW);   // turn the LED on (HIGH is the voltage level)
      }
   delay(2000);
    }
