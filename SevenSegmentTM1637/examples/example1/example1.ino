#include "SevenSegmentTM1637.h"

const byte PIN_CLK = 4; // define CLK pin (any digital pin)
const byte PIN_DIO = 5; // define DIO pin (any digital pin)
SevenSegmentTM1637 display(PIN_CLK, PIN_DIO);

const int buttonPin1 = 6;
const int buttonPin2 = 7;

int buttonState1 = 0;
int buttonState2 = 0;

int checkBTN1 = 0;
int checkBTN2 = 0;

int data = 0;

void setup()
{
  Serial.begin(115200);
  Serial.println("Micro Project Thailand ~^.^~ ");

  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);

  display.begin();           // initializes the display
  display.setBacklight(100); // set the brightness to 100 %
  display.print("8888");     // display INIT on the display
  delay(1000);               // wait 1000 ms
  display.clear();
  display.print(data);
};

// run loop (forever)

void loop()
{

  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

  if (buttonState1 == HIGH)
  {
    if (checkBTN1 == 0)
    {
      checkBTN1 = 1;
      Serial.println("BTN 1 ");
      display.clear();
      data--;
      display.print(data);
    }
  }
  else
  {
    checkBTN1 = 0;
  }

  if (buttonState2 == HIGH)
  {
    if (checkBTN2 == 0)
    {
      checkBTN2 = 1;
      Serial.println("BTN 2 ");
      display.clear();
      data++;
      display.print(data);
    }
  }
  else
  {
    checkBTN2 = 0;
  }

  delay(100);
};
