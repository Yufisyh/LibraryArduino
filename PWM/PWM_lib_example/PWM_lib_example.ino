/*

  Mimics the fade example but with an extra parameter for frequency. It should dim but with a flicker
  because the frequency has been set low enough for the human eye to detect. This flicker is easiest to see when
  the LED is moving with respect to the eye and when it is between about 20% - 60% brighness. The library
  allows for a frequency range from 1Hz - 2MHz on 16 bit timers and 31Hz - 2 MHz on 8 bit timers. When
  SetPinFrequency()/SetPinFrequencySafe() is called, a bool is returned which can be tested to verify the
  frequency was actually changed.

  This example runs on mega and uno.
*/

#include <PWM.h>
int32_t frequency = 3333; //frequency (in Hz)

void setup()
{
  Serial.begin(9600);
  InitTimersSafe();
  pinMode(9, OUTPUT);
}

void loop()
{
  for (int i = 0; i < 3333; i++) {
    pwmWrite(9, i);
    delay(1);
    Serial.println(i);
  }
}
