#include <SensorTCS.h>

SensorTCS tcs1(8,9,10,11,12);
SensorTCS tcs2(8,9,10,11,12);
int warna1;
int warna2;
void setup() {
Serial.begin (9600);
tcs1.ReadFrequency();
tcs2.ReadFrequency();
}

void loop() {
warna1 = tcs1.ReadColor();
warna2 = tcs2.ReadColor();
Serial.println("Warna dari arduino1 " + String(warna1));
Serial.println("  ");
delay(500);
Serial.println("Warna dari arduino2 " + String(warna2));
delay(500);
}
