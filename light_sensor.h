#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include "Arduino.h"

class LightSensor {
  private:
    int lightPin;

  public:
    LightSensor(int lightPin);
    int getLight();
};

#endif
