

#ifndef SensorTCS_h
#define SensorTCS_h

#include <Arduino.h>

class SensorTCS
{
public:
	SensorTCS(uint8_t S0, uint8_t S1, uint8_t S2, uint8_t S3, uint8_t output);
	int ReadColor();
	int ReadFrequency();
private:
	uint8_t _S0;
	uint8_t _S1;
	uint8_t _S2;
	uint8_t _S3;
	uint8_t _output;
	int color=0;
    int frequency = 0;

};

#endif
