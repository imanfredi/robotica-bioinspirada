#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

enum DirectionState
{
    forward,
    backward
};

class Motor
{
private:
    int speedPin;
    int backwardPin;
    int forwardPin;
    int currentSpeed;
    DirectionState directionState;

public:
    Motor(int speedPin, int backwardPin, int forwardPin);
    void setup();
    void setDirection(DirectionState directionState);
    void setSpeed(int speed);
    void goForwards();
    void goBackwards();
    void stop();
};

#endif