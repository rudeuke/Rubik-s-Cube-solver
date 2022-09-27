#include <Servo.h>
#include "Arduino.h"
#include "MyServo.h"
#include "ServoHandler.h"
#include "Cube.h"

String data = "";
String algorithm = "EVGCSM"; // temporary sequence to make crosses

void setup()
{
    Serial.begin(9600);

    ROTATION_SERVO.servo.attach(ROTATION_SERVO.pin);
    ROTATION_SERVO.servo.write(ROTATION_SERVO.angle1);

    BLOCK_SERVO.servo.attach(BLOCK_SERVO.pin);
    BLOCK_SERVO.servo.write(BLOCK_SERVO.angle1);

    FLIP_SERVO.servo.attach(FLIP_SERVO.pin);
    FLIP_SERVO.servo.write(FLIP_SERVO.angle1);
}

void loop()
{
    if (Serial.available() > 0)
    {
        Cube myCube;
        data = Serial.readString();

        if (data != "1")
        {
            algorithm = data;
            myCube.solve(algorithm);
        }
        else
        {
            myCube.scan();
        }
    }
}

// FOR TESTING
// if (data == "f\n")
// {
//     ServoHandler::flipBack();
// }
// else if (data == "t\n")
// {
//     ServoHandler::turnClockwise();
// }
// else if (data == "1\n")
// {
//     BLOCK_SERVO.servo.write(BLOCK_SERVO.angle1);
// }
// else if (data == "2\n")
// {
//     BLOCK_SERVO.servo.write(BLOCK_SERVO.angle2);
// }
// else if (data == "3\n")
// {
//     ROTATION_SERVO.servo.write(ROTATION_SERVO.angle1);
// }
// else if (data == "4\n")
// {
//     ROTATION_SERVO.servo.write(ROTATION_SERVO.angle2);
// }
// else if (data == "5\n")
// {
//     FLIP_SERVO.servo.write(FLIP_SERVO.angle1);
// }
// else if (data == "6\n")
// {
//     FLIP_SERVO.servo.write(FLIP_SERVO.angle2);
// }
// else if (data == "scan\n")
// {
//     myCube.scan();
// }
// else if (data == "solve\n")
// {
//     myCube.solve(algorithm);
// }