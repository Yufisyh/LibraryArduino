#include <ultrasonic02.h>

ultrasonic02 ultrasonik1(2,3);
ultrasonic02 ultrasonik2(4,5);
ultrasonic02 ultrasonik3(6,7);
ultrasonic02 ultrasonik4(8,9);

double jarak1;
double jarak2;
double jarak3;
double jarak4;

void setup(){
  Serial.begin(9600);
}

void loop(){

  jarak1=ultrasonik1.baca();
  //jarak1=ultrasonik1.baca(0);
  jarak2=ultrasonik2.baca();
  //jarak2=ultrasonik2.baca(0);
  jarak3=ultrasonik3.baca();
  //jarak3=ultrasonik3.baca(0);
  jarak4=ultrasonik4.baca();
  //jarak4=ultrasonik4.baca(0);
  
  Serial.print(jarak1);
  Serial.print("cm(sensor1)");
  Serial.println();
  Serial.print(jarak2);
  Serial.print("cm(sensor2)");
  Serial.println();
  Serial.print(jarak3);
  Serial.print("cm(sensor3)");
  Serial.println();
  Serial.print(jarak4);
  Serial.print("cm(sensor4)");
  Serial.println();
  
  delay(500);
}
