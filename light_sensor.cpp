#include "light_sensor.h"

LightSensor::LightSensor(int lightPin) : lightPin(lightPin) {
}


int LightSensor::getLight() {
    return analogRead(this->lightPin);
}
