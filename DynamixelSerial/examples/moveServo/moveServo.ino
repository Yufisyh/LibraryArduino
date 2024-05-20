#include <DynamixelSerial.h>
int ID = 7;
void setup() {
  Dynamixel.setSerial(&Serial1); // &Serial - Arduino UNO/NANO/MICRO, &Serial1, &Serial2, &Serial3 - Arduino Mega
  Dynamixel.begin(1000000, 2); // Inicialize the servo at 1 Mbps and Pin Control 2
  delay(1000);
}

void loop() {

  Dynamixel.moveSpeed(ID, 0, 1023);
  Dynamixel.ledStatus(ID, ON);
  delay(3000);
  Dynamixel.moveSpeed(ID, 1023, 512);
  Dynamixel.ledStatus(ID, ON);
  delay(3000);
}
