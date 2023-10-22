#ifndef CAR_H
#define CAR_H

#include <Arduino.h>
#include "motor.h"
#include "ultrasonic.h"
#include "light_sensor.h"

class Car
{
private:
    Motor motorLeft;
    Motor motorRight;
    int speed;

public:
    Car(Motor motorLeft, Motor motorRight);
    void setSpeed(int speed);
    int getSpeed();
    void stop();
    void goForwards();
    void goBackwards();
    void turnLeft();
    void turnRight();
};

#endif
