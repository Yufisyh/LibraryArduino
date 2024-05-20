#ifndef UltraLib_h
#include "Arduino.h"
#include "NewPing.h"
#define UltraLib_h
#define SONAR_NUM     4 // Number of sensors.
#define MAX_DISTANCE  250 // Maximum distance (in cm) to ping.
#define PING_INTERVAL 30

class UltraLib{

    private :
        
        unsigned long pingTimer[SONAR_NUM]; // Holds the times when the next ping should happen for each sensor.
        unsigned int cm[SONAR_NUM];         // Where the ping distances are stored.
        uint8_t currentSensor = 0;          // Keeps track of which sensor is active.
        NewPing sonar[SONAR_NUM] = {     // Sensor object array.
            NewPing(2, 3, MAX_DISTANCE), // Each sensor's trigger pin, echo pin, and max distance to ping.
            NewPing(4, 5, MAX_DISTANCE),
            NewPing(6, 7, MAX_DISTANCE),
            NewPing(8, 9, MAX_DISTANCE),
    };

    public :
        UltraLib :: UltraLib();
        void utama();
        void disetup();

};

#endif