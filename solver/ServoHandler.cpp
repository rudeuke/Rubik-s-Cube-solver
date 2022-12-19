#include <Servo.h>
#include "MyServo.h"
#include "ServoHandler.h"
#include "Arduino.h"

void ServoHandler::blockCube()
{
    BLOCK_SERVO.servo.write(BLOCK_SERVO.angle2);
    delay(_waitMedium);
}

void ServoHandler::unblockCube()
{
    BLOCK_SERVO.servo.write(BLOCK_SERVO.angle1);
    delay(_waitMedium);
}

void ServoHandler::basePosition1(int offset)
{
    ROTATION_SERVO.servo.write(ROTATION_SERVO.angle1 - offset);
    if (offset == 0)
    {
        delay(_waitMedium);
    }
    else
    {
        delay(_waitLong);
    }
}

void ServoHandler::basePosition2(int offset)
{
    ROTATION_SERVO.servo.write(ROTATION_SERVO.angle2 + offset);
    if (offset == 0)
    {
        delay(_waitMedium);
    }
    else
    {
        delay(_waitLong);
    }
}

void ServoHandler::armFlip()
{
    delay(_waitVeryShort);
    for (int j = FLIP_SERVO.angle1; j < FLIP_SERVO.angle2; j++)
    { // for slower movement of flip arm
        delay(7);
        FLIP_SERVO.servo.write(j);
    }
    FLIP_SERVO.servo.write(FLIP_SERVO.angle1);
    delay(_waitMedium);
}

void ServoHandler::turnClockwise(int numberOfTimes)
{
    for (int i = 0; i < numberOfTimes; i++)
    {
        blockCube();
        basePosition2(7);
        basePosition2();
        unblockCube();
        basePosition1();
    }
}

void ServoHandler::turnCounterclockwise(int numberOfTimes)
{
    for (int i = 0; i < numberOfTimes; i++)
    {
        basePosition2();
        delay(_waitShort);
        blockCube();
        basePosition1(7);
        basePosition1();
        unblockCube();
    }
}

void ServoHandler::flipBack(int numberOfTimes)
{
    for (int i = 0; i < numberOfTimes; i++)
    {
        armFlip();
    }
}

void ServoHandler::flipRight(int numberOfTimes)
{
    basePosition2();
    for (int i = 0; i < numberOfTimes; i++)
    {
        armFlip();
    }
    basePosition1();
}

void ServoHandler::initialiseScan()
{
    digitalWrite(LED_PIN, HIGH);
    basePosition2();
    delay(_waitScan);
    Serial.println("u");

    basePosition1();
    armFlip();
    basePosition2();
    delay(_waitScan);
    Serial.println("f");

    armFlip();
    delay(_waitScan);
    Serial.println("l");

    armFlip();
    delay(_waitScan);
    Serial.println("b");

    armFlip();
    delay(_waitScan);
    Serial.println("r");

    armFlip();
    basePosition1();
    armFlip();
    basePosition2();
    delay(_waitScan);
    Serial.println("d");
    digitalWrite(LED_PIN, LOW);

    basePosition1();
    armFlip();
    armFlip();
}