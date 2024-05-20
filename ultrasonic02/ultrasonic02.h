#ifndef ultrasonic02_h
#define ultrasonic02_h

#include <Arduino.h>



class ultrasonic02
{
      public:
             ultrasonic02(int triger, int echo);
             double baca();
      private:
              int trigerpin;
              int echopin;
};

#endif
