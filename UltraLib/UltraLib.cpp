#include "Arduino.h"
#include "NewPing.h"
#include "UltraLib.h"

void echoCheck() { // If ping received, set the sensor distance to array.
  if (sonar[currentSensor].check_timer())
    cm[currentSensor] = sonar[currentSensor].ping_result / US_ROUNDTRIP_CM;
}

void oneSensorCycle() { // Sensor ping cycle complete, do something with the results.
  // The following code would be replaced with your code that does something with the ping results.
  for (uint8_t i = 0; i < SONAR_NUM; i++) {
    Serial.print(i);
    Serial.print("=");
    Serial.print(cm[i]);
    Serial.print("cm ");
  }
  Serial.println();
}

UltraLib :: UltraLib(){

};

void UltraLib :: disetup(){
    pingTimer[0] = millis() + 75;           // First ping starts at 75ms, gives time for the Arduino to chill before starting.
    for (uint8_t i = 1; i < SONAR_NUM; i++) // Set the starting time for each sensor.
        pingTimer[i] = pingTimer[i - 1] + PING_INTERVAL;
};

void UltraLib :: utama(){
      for (uint8_t i = 0; i < SONAR_NUM; i++) { // Loop through all the sensors.
      if (millis() >= pingTimer[i]) {         // Is it this sensor's time to ping?
        pingTimer[i] += PING_INTERVAL * SONAR_NUM;  // Set next time this sensor will be pinged.
        if (i == 0 && currentSensor == SONAR_NUM - 1) oneSensorCycle(); // Sensor ping cycle complete, do something with the results.
            sonar[currentSensor].timer_stop();          // Make sure previous timer is canceled before starting a new ping (insurance).
            currentSensor = i;                          // Sensor being accessed.
            cm[currentSensor] = 0;                      // Make distance zero in case there's no ping echo for this sensor.
            sonar[currentSensor].ping_timer(echoCheck); // Do the ping (processing continues, interrupt will call echoCheck to look for echo).
        }
      }
};
