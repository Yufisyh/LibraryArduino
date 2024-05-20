#include "ledkedip.h"
#include "Arduino.h"

ledkedip::ledkedip (int led1){
      diode1=led1;
}

void ledkedip:: PinSetup(){
      pinMode(diode1, OUTPUT);
}

void ledkedip:: ledkedip1(int waktu){
      digitalWrite(diode1, HIGH);
      delay(waktu);
      digitalWrite(diode1, LOW);
      delay(waktu);
}