#include <ledkedip.h>
ledkedip kedip(12);

void setup() {
  kedip.PinSetup();
}

void loop() {
  kedip.ledkedip1(100);
  kedip.ledkedip1(500);
  kedip.ledkedip1(1000);
  kedip.ledkedip1(2000);
}
