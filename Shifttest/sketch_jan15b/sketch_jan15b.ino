#include <SPI.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.begin();
  for(int i = 0; i < 14; i++){
    pinMode(i, OUTPUT);
  }
  digitalWrite(8, LOW);
  digitalWrite(8, HIGH);
  delay(2000);
  digitalWrite(7, LOW);
  delay(2000);
  digitalWrite(7, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 14; i++){
  digitalWrite(i, HIGH);
  }
}
