
#include "Arduino.h"
#include "SensorTCS.h"



SensorTCS::SensorTCS(uint8_t S0, uint8_t S1, uint8_t S2, uint8_t S3, uint8_t output)
{
	pinMode(S0, OUTPUT);
	pinMode(S1, OUTPUT);
	pinMode(S2, OUTPUT);
	pinMode(S3, OUTPUT);
	pinMode(output, INPUT);

	_S0 = S0;
	_S1 = S1;
	_S2 = S2;
	_S3 = S3;
	_output = output;
}

int SensorTCS::ReadFrequency()
{
     // Atur penskalaan ke 100%
		digitalWrite(_S0, HIGH);
		digitalWrite(_S1, HIGH);
}

int SensorTCS::ReadColor()
{
  // mengatur filter merah
  digitalWrite(_S2,LOW);
  digitalWrite(_S3,LOW);
  frequency = pulseIn(_output, LOW);  // membaca keluaran frekuensi merah
  int R = frequency;
  
  // mengatur filter hijau
  digitalWrite(_S2,HIGH);
  digitalWrite(_S3,HIGH);
  frequency = pulseIn(_output, LOW);  // membaca keluaran frekuensi hijau
  int G = frequency;
  
  // mengatur filter biru
  digitalWrite(_S2,LOW);
  digitalWrite(_S3,HIGH);
  frequency = pulseIn(_output, LOW);  // membaca keluaran frekuensi biru
  int B = frequency;
  
  if((R<18&& R>1) && (G<20 && G>1) && (G<19 && G>1)){
    color = 1; // PUTIH
  }
  if((R<60 && R>41) && (G<61 && G>41) && (B<46 && B>33)){
    color = 2; // HITAM
  }
  if((R<40 && R>25) && (G<40 && G>20) && (B<30 && B>18)){
    color = 3; // ABUABU
  }
  return color;  

}
