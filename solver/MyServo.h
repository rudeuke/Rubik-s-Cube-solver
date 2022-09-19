#ifndef MyServo_h
#define MyServo_h
#include <Servo.h>

class MyServo
{
public:
    Servo servo;
    int pin;
    int angle1;
    int angle2;

    MyServo(Servo servo, int pin, int angle1, int angle2);
};

extern MyServo ROTATION_SERVO;
extern MyServo BLOCK_SERVO;
extern MyServo FLIP_SERVO;

#endif