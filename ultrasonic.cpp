#include "ultrasonic.h"

Ultrasonic::Ultrasonic(int trigPin, int echoPin)
    : trigPin(trigPin), echoPin(echoPin)
{
}
void Ultrasonic::setup() {
    pinMode(this->trigPin, OUTPUT);
    pinMode(this->echoPin, INPUT);
}

float Ultrasonic::getDistance() {
    float distance;
    long duration;
    digitalWrite(this->trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(this->trigPin, LOW);
    duration = pulseIn(this->echoPin, HIGH);
    distance = (duration * 0.0343) / 2;
    return distance;
}