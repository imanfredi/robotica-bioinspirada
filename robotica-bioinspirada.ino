
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

//Light Sensor
int inRight = A0;
int inLeft = A1;

//ultrasonic
int trigPin = 13;
int echoPin = 12;

Motor motorLeft(enA, inBackwardA, inForwardA);
Motor motorRight(enB, inBackwardB, inForwardB);
Ultrasonic ultrasonic(trigPin,echoPin);
LightSensor lightSensorLeft(inLeft);
LightSensor lightSensorRight(inRight);
Car car(motorLeft,motorRight);

void setup() {
  Serial.begin(9600);
  motorLeft.setup();
  motorRight.setup();
  ultrasonic.setup();

}

void loop() {

  float distance = ultrasonic.getDistance();
  // int lightRight = lightSensorRight.getLight();
  int lightLeft = lightSensorLeft.getLight();
  // Serial.println(lightRight);
  Serial.println(lightLeft);


}
