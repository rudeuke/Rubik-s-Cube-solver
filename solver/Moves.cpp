#include "Moves.h"
#include "ServoHandler.h"

void Moves::Uu()
{
    ServoHandler::flipBack(2);
    ServoHandler::turnClockwise();
}

void Moves::Up()
{
    ServoHandler::flipBack(2);
    ServoHandler::turnCounterclockwise();
}

void Moves::U2()
{
    ServoHandler::flipBack(2);
    ServoHandler::turnClockwise(2);
}

void Moves::Rr()
{
    ServoHandler::flipRight();
    ServoHandler::turnClockwise();
}

void Moves::Rp()
{
    ServoHandler::flipRight();
    ServoHandler::turnCounterclockwise();
}

void Moves::R2()
{
    ServoHandler::flipRight();
    ServoHandler::turnClockwise(2);
}

void Moves::Ff()
{
    ServoHandler::flipBack(3);
    ServoHandler::turnClockwise();
}

void Moves::Fp()
{
    ServoHandler::flipBack(3);
    ServoHandler::turnCounterclockwise();
}

void Moves::F2()
{
    ServoHandler::flipBack(3);
    ServoHandler::turnClockwise(2);
}

void Moves::Dd()
{
    ServoHandler::turnClockwise();
}

void Moves::Dp()
{
    ServoHandler::turnCounterclockwise();
}

void Moves::D2()
{
    ServoHandler::turnClockwise(2);
}

void Moves::Ll()
{
    ServoHandler::flipRight(3);
    ServoHandler::turnClockwise();
}

void Moves::Lp()
{
    ServoHandler::flipRight(3);
    ServoHandler::turnCounterclockwise();
}

void Moves::L2()
{
    ServoHandler::flipRight(3);
    ServoHandler::turnClockwise(2);
}

void Moves::Bb()
{
    ServoHandler::flipBack();
    ServoHandler::turnClockwise();
}

void Moves::Bp()
{
    ServoHandler::flipBack();
    ServoHandler::turnCounterclockwise();
}

void Moves::B2()
{
    ServoHandler::flipBack();
    ServoHandler::turnClockwise(2);
}