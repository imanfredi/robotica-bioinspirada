#include "Motor.h"

Motor::Motor(int speedPin, int backwardPin, int forwardPin)
    : speedPin(speedPin), backwardPin(backwardPin), forwardPin(forwardPin)
{
    this->currentSpeed = 0;
    this->directionState = DirectionState::forward;
}

void Motor::setup()
{
    pinMode(this->speedPin, OUTPUT);
    pinMode(this->backwardPin, OUTPUT);
    pinMode(this->forwardPin, OUTPUT);
    digitalWrite(this->backwardPin, LOW);
    digitalWrite(this->forwardPin, LOW);
    analogWrite(this->speedPin, 0);
}

void Motor::setDirection(DirectionState directionState)
{
    this->directionState = directionState;

    switch (this->directionState)
    {
    case DirectionState::forward:
        digitalWrite(this->backwardPin, LOW);
        digitalWrite(this->forwardPin, HIGH);
        break;
    case DirectionState::backward:
        digitalWrite(this->backwardPin, HIGH);
        digitalWrite(this->forwardPin, LOW);
        break;
    }
}

void Motor::setSpeed(int speed)
{
    this->currentSpeed = speed;
    analogWrite(this->speedPin, this->currentSpeed);
}

void Motor::goForwards()
{
    this->setDirection(DirectionState::forward);
}

void Motor::goBackwards()
{
    this->setDirection(DirectionState::backward);
}

void Motor::stop()
{
    this->setSpeed(0);
}
