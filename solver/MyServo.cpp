#include "MyServo.h"
#include <Servo.h>

MyServo::MyServo(Servo servo, int pin, int angle1, int angle2)
{
    this->servo = servo;
    this->pin = pin;
    this->angle1 = angle1;
    this->angle2 = angle2;
}

Servo rotation;
Servo block;
Servo flip;
MyServo ROTATION_SERVO = MyServo(rotation, 9, 13, 110);
MyServo BLOCK_SERVO = MyServo(block, 10, 50, 128);
MyServo FLIP_SERVO = MyServo(flip, 11, 20, 75);