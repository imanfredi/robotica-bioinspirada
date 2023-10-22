
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

Motor motorLeft(enA, inBackwardA, inForwardA);
Motor motorRight(enB, inBackwardB, inForwardB);
Ultrasonic ultrasonic(trigPin, echoPin);
LightSensor lightSensorLeft(inLeft);
LightSensor lightSensorRight(inRight);
Car car(motorLeft, motorRight);

// State variables
int distanceThreshold = 50;
int lightThresholdDifference = 10;
int lightThreshold = 250;
long previousMillis = 0;
long interval = 50;

void setup()
{
    Serial.begin(9600);
    motorLeft.setup();
    motorRight.setup();
    ultrasonic.setup();
    car.stop();
}

// Braitenber Tímido
// void loop(){

//     long currentMillis = millis();
//     float distance = ultrasonic.getDistance();

//     if (currentMillis - previousMillis >= interval)
//     {
//         previousMillis = currentMillis;

//         if (distance > distanceThreshold && car.getSpeed() != 100)
//         {
//             car.goForwards();
//             car.setSpeed(100);
//         }
//         else if (distance <= distanceThreshold)
//         {
//             car.stop();
//         }
//     }
// }

// Afraid from light

// void loop()
// {
//     long currentMillis = millis();
//     float distance = ultrasonic.getDistance();
//     int lightRight = lightSensorRight.getLight();
//     int lightLeft = lightSensorLeft.getLight();

//     if (currentMillis - previousMillis >= interval)
//     {
//         previousMillis = currentMillis;

//         // Analizo luces. Si la cantidad de luz es superior a X entonces tengo que esquivar.
//         // Si hay más luz de la derecha --> izquierda
//         // Si hay más luz de la izquierda --> derecha
//         // Si la distancia es parecida anda para atrás
//         // Si hay un objeto freno
//         if (lightLeft > lightThreshold || lightRight > lightThreshold)
//         {
//             int lightDifference = lightLeft - lightRight;
//             if (abs(lightDifference) < lightThresholdDifference)
//             {
//                 // Both sensors detect similar light levels, move backwards. La luz viene de frente.
//                 car.goBackwards();
//                 car.setSpeed(100);
//             }
//             else if (lightDifference > 0)
//             {
//                 // lightDifference > 0 --> hay más luz de la izquierda. Giro a la derecha
//                 car.stop();
//                 car.setSpeed(100);
//                 car.turnRight();
//             }
//             else
//             {
//                 // lightDifference < 0 --> hay más luz de la izquierda. Giro a la izquierda
//                 car.stop();
//                 car.setSpeed(100);
//                 car.turnLeft();
//             }
//         }
//         else
//         {
//             if (distance < distanceThreshold)
//             {
//                 car.stop();
//                 car.setSpeed(100);
//                 car.goBackwards();
//             }
//             else
//             {
//                 car.setSpeed(100);
//                 car.goForwards();
//             }
//         }
//     }
// }

// Light Follower
// void loop()
// {
//     long currentMillis = millis();
//     float distance = ultrasonic.getDistance();
//     int lightRight = lightSensorRight.getLight();
//     int lightLeft = lightSensorLeft.getLight();

//     if (currentMillis - previousMillis >= interval)
//     {
//         previousMillis = currentMillis;
//         // Analizo luces. Si la cantidad de luz es superior a X entonces tengo que seguir.
//         // Si hay más luz de la derecha --> derecha
//         // Si hay más luz de la izquierda --> izquierda
//         // Si la distancia es parecida anda para adelante
//         // Si hay un objeto freno
//         if (lightLeft > lightThreshold || lightRight > lightThreshold)
//         {
//             int lightDifference = lightLeft - lightRight;
//             if (abs(lightDifference) < lightThresholdDifference)
//             {
//                 // Both sensors detect similar light levels, move forwards. La luz viene de frente voy hacia adelante.
//                 if (distance < distanceThreshold)
//                 {
//                     car.stop();
//                     car.setSpeed(100);
//                     car.goBackwards();
//                 }
//                 else
//                 {
//                     car.setSpeed(100);
//                     car.goForwards();
//                 }
//             }
//             else if (lightDifference > 0)
//             {
//                 // lightDifference > 0 --> hay más luz de la izquierda. Giro a la izquierda
//                 car.stop();
//                 car.setSpeed(100);
//                 car.turnLeft();
//             }
//             else
//             {
//                 // lightDifference < 0 --> hay más luz de la derecha. Giro a la derecha
//                 car.stop();
//                 car.setSpeed(100);
//                 car.turnRight();
//             }
//         }
//         else
//         {
//             if (distance < distanceThreshold)
//             {
//                 car.stop();
//                 car.setSpeed(100);
//                 car.goBackwards();
//             }
//             else
//             {
//                 car.setSpeed(100);
//                 car.goForwards();
//             }
//         }
//     }
// }
