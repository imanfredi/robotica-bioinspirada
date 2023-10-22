#include "motor.h"
#include "ultrasonic.h"
#include "light_sensor.h"
#include "car.h"

// Motor A (Left) connections
int enA = 9;
int inBackwardA = 8;
int inForwardA = 7;

// Motor B (Right) connections
int inBackwardB = 5;
int inForwardB = 4;
int enB = 3;

// Light Sensor
int inRight = A0;
int inLeft = A1;

// ultrasonic
int trigPin = 13;
int echoPin = 12;

int distanceThreshold = 20;
int lightThreshold = 100;

long previousMillis = 0;
long interval = 1000;

Motor motorLeft(enA, inBackwardA, inForwardA);
Motor motorRight(enB, inBackwardB, inForwardB);
Ultrasonic ultrasonic(trigPin, echoPin);
LightSensor lightSensorLeft(inLeft);
LightSensor lightSensorRight(inRight);
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
    int lightRight = lightSensorRight.getLight();
    int lightLeft = lightSensorLeft.getLight();

    if (currentMillis - previousMillis >= interval)
    {
        previousMillis = currentMillis;

        if (distance < distanceThreshold)
        {
            car.stop();
        }
        else
        {
            int lightDifference = lightLeft - lightRight;

            if (abs(lightDifference) < lightThreshold)
            {
                // Both sensors detect similar light levels, move backwards
                car.goBackwards();
                car.setSpeed(100);
            }
            else if (lightDifference > 0)
            {
                // Left sensor detects more light, turn left
                car.stop();
                car.turnLeft();
                car.setSpeed(100);
            }
            else
            {
                // Right sensor detects more light, turn right
                car.stop();
                car.turnRight();
                car.setSpeed(100);
            }
        }
    }
}
