#ifndef TPA81buatan_h
#define TPA81buatan_h

#define 	AMBIENT		0x01
#define		POINT_BASE	0x02

class TPA81buatan
{
private:
	int address;
	int sensor[9];
	void sendCommand(uint8_t cmd);
	int receiveData();

public:
	TPA81buatan();
	TPA81buatan(uint8_t addr);
	void setup(uint8_t addr);
	void changeAddress(uint8_t addr);
	int getAmbient();
	int getPoint(uint8_t point);
	int getAll(int points[]);
    void settingbaudrate(int baudrate);
    void printhasilsensor();
    int derajatnilai();
};

#endif