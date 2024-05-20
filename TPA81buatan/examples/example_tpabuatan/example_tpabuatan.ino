#include <Wire.h>
#include <TPA81buatan.h>
TPA81buatan tpa;

int derajat;
int sensor[9];

void setup() {
  tpa.settingbaudrate(9600);
}

void loop() {
 
 tpa.printhasilsensor();
 derajat=tpa.derajatnilai();
 
 for (int i = 1; i<=9; i++){
    sensor[i]=tpa.getPoint(i);
  }
  delay(500);
}
