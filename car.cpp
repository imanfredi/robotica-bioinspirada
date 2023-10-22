#include "Car.h"
  
Car::Car(Motor motorLeft, Motor motorRight)
    : motorLeft(motorLeft), motorRight(motorRight)
{
    this->speed = 0;
}

void Car::setSpeed(int speed)
{
    this->speed = speed;
    this->motorLeft.setSpeed(this->speed);
    this->motorRight.setSpeed(this->speed);
}

void Car::stop()
{
    this->motorLeft.stop();
    this->motorRight.stop();
}

void Car::goForwards()
{
    this->motorLeft.goForwards();
    this->motorRight.goForwards();
}

void Car::goBackwards()
{
    this->motorLeft.goBackwards();
    this->motorRight.goBackwards();
}

void Car::turnLeft()
{
    this->motorRight.goForwards();
    this->motorLeft.goBackwards();
}

void Car::turnRight()
{
    this->motorRight.goBackwards();
    this->motorLeft.goForwards();
}
