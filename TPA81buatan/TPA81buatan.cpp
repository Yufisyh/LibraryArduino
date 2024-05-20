
#include "Arduino.h"
#include "Wire.h"
#include "TPA81buatan.h"

TPA81buatan::TPA81buatan()
{
	address = 0xD0 >> 1;
}

/**
 * Initialize object with TPA81 custon I2C address.
 *
 * The TPA81 can be set to any of eight I2C addresses:
 * 0xD0, 0xD2, 0xD4, 0xD6, 0xD8, 0xDA, 0xDC, 0xDE
 * 
 * The factory default shipped address is 0xD0.
 *
 * @param	addr	TPA81 I2C address
 */
TPA81buatan::TPA81buatan(uint8_t addr)
{
	setup(addr);
}
void TPA81buatan::settingbaudrate(int baudrate){
    Serial.begin(baudrate);
}

void TPA81buatan::setup(uint8_t addr)
{
	// Check if address is valid
	if (((addr & 0xF0) == 0xD0) && ((addr & 0x0F) % 2 == 0)) {
		address = addr >> 1;
	} else {
		// Fallback to default address
		address = 0xD0 >> 1;
	}
}

/**
 * Send Command To TPA81
 * 
 * @param 	cmd 	TPA81 register number
 */
void TPA81buatan::sendCommand(uint8_t cmd)
{
	Wire.beginTransmission(address);
	Wire.write(cmd);
	Wire.endTransmission();
}

/**
 * Read single data from TPA81
 * 
 * @return 	data
 */
int TPA81buatan::receiveData()
{
	Wire.requestFrom(address, 1);

	long start = millis();
	while (Wire.available() < 1) {
		if (millis() - start > 5)
			return 0;
	}

	return Wire.read();
}

void TPA81buatan::changeAddress(uint8_t addr)
{
	Wire.beginTransmission(address);
	Wire.write(0);
	Wire.write(0xA0);
	Wire.endTransmission();

	Wire.beginTransmission(address);
	Wire.write(0);
	Wire.write(0xAA);
	Wire.endTransmission();

	Wire.beginTransmission(address);
	Wire.write(0);
	Wire.write(0xA5);
	Wire.endTransmission();

	Wire.beginTransmission(address);
	Wire.write(0);
	Wire.write(addr);
	Wire.endTransmission();

	address = addr >> 1;
}

/**
 * Read ambient temperature
 * 
 * @return 	ambient temperature
 */
int TPA81buatan::getAmbient()
{
	sendCommand(AMBIENT);
	return receiveData();
}

/**
 * Read temperature from a certain point
 * 
 * @param  	point 	point number, 1 to 8
 * @return 			point temperature
 */
int TPA81buatan::getPoint(uint8_t point)
{
	if (point < 1 && point > 8) {
		return 0;
	}

	sendCommand(POINT_BASE + point - 1);
	return receiveData();
}

/**
 * Read ambient and all temperature points
 * 
 * @param  points 	point temperature buffer
 * @return        	ambient temperature
 */
int TPA81buatan::getAll(int points[])
{
	sendCommand(AMBIENT);

	Wire.requestFrom(address, (int) 9);

	long start = millis();
	while (Wire.available() < 9) {
		if (millis() - start > 10)
			return 0;
	}

	int ambient = Wire.read();
	for (int i = 0; i < 8; i++)
	{
		points[i] = Wire.read();
	}

	return ambient;
}


void TPA81buatan::printhasilsensor(){
    for (int i = 1; i<=8; i++){
    sensor[i] = getPoint(i);
    Serial.print(sensor[i]);
    Serial.print(" ");
    }
    Serial.print("\n");
}

int TPA81buatan::derajatnilai(){
     int maks = sensor[0];
     int indexmaks = 0 ;
	 int derajat = 0;
  for(int i=0;i<=8;i++){
    if (sensor[i]>50){
      if( sensor[i] > maks){
        maks=sensor[i];
        indexmaks = i;
      }
    }
  }
	if(maks > 50){
    Serial.println("sensor terdeteksi pada point ke " + String(indexmaks));
  }
  
  else{
    Serial.println("sensor tidak mendeteksi api");
  }
  
  if((indexmaks == 4) || (indexmaks == 5)){
    Serial.println("Posisi api berada di depan sensor");
  }
  
  if((indexmaks < 4) && (indexmaks >0)){
    derajat = (4.5-indexmaks)*5.12;
    Serial.println("Geser sensor ke arah kiri sebesar " + String(derajat) + " derajat" );
  }

  if((indexmaks > 5)&& (indexmaks >0)){
    derajat = (indexmaks-4.5)*5.12;
    Serial.println("Geser sensor ke arah kanan sebesar " + String(derajat) + " derajat" );
  }
    return derajat;
}
