#include "motor.h"
#include "ultrasonic.h"
#include "car.h"

// Motor A (Left) connections
int enA = 9;
int inBackwardA = 8;
int inForwardA = 7;

// Motor B (Right) connections
int inBackwardB = 5;
int inForwardB = 4;
int enB = 3;

// ultrasonic
int trigPin = 13;
int echoPin = 12;

int distanceThreshold = 20;

long previousMillis = 0;
long interval = 1000;

Motor motorLeft(enA, inBackwardA, inForwardA);
Motor motorRight(enB, inBackwardB, inForwardB);
Ultrasonic ultrasonic(trigPin, echoPin);
Car car(motorLeft, motorRight);

void setup()
{
    Serial.begin(9600);
    motorLeft.setup();
    motorRight.setup();
    ultrasonic.setup();
}

void loop()
{
    long currentMillis = millis();
    float distance = ultrasonic.getDistance();

    if (currentMillis - previousMillis >= interval)
    {
        previousMillis = currentMillis;

        if (distance > distanceThreshold && car.getSpeed != 100)
        {
            car.setSpeed(100);
        }
        else if (distance <= distanceThreshold)
        {
            car.stop();
        }
    }
}
