#include <Arduino.h>
#include <ultrasonic02.h>

ultrasonic02::ultrasonic02(int trigerr, int echo)
{
       pinMode(trigerr, OUTPUT);
       pinMode(echo, INPUT);
       trigerpin=trigerr;
       echopin=echo;
}

double ultrasonic02::baca()
{
       digitalWrite(trigerpin, LOW);
       delayMicroseconds(2);
       digitalWrite(trigerpin, HIGH);
       delayMicroseconds(10);
       digitalWrite(trigerpin, LOW);
       double durasi=pulseIn(echopin, HIGH);
       int hasil=((durasi/2)*0.0343);

       return hasil;
}
