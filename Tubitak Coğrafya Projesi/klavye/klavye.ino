#include "Keyboard.h"
bool state;
bool state_old;

void setup() {
  Keyboard.begin();
  pinMode(12,INPUT);
  Serial.begin(9600);
}

void loop() {
  state=digitalRead(12);
  if(state==HIGH&&state_old!=state){
    Serial.println("A");
    Keyboard.press('n');
  }
  
  state_old=state;
}
