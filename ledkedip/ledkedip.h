#ifndef ledkedip_h
#define ledkedip_h
#include "Arduino.h"

class ledkedip {

  private:
    int diode1;

  public :
    ledkedip::ledkedip (int led1);
    void PinSetup();
    void ledkedip1(int waktu);
};

#endif