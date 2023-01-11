#include "Arduino.h"
#include "Cube.h"
#include "Moves.h"
#include "ServoHandler.h"

const char FACE_PATTERN[6] = {'U', 'R', 'F', 'D', 'L', 'B'};
char tempColor[6];

void Cube::scan()
{
    ServoHandler::initialiseScan();
}

void Cube::solve(String moves)
{
    int numberOfMoves = (int)moves.length() - 1;

    for (int i = 0; i < numberOfMoves; i++)
    {
        char nextMove = decode(moves[i]);
        makeMove(nextMove);
    }
}

void Cube::updateOrientation()
{
    _color[0] = tempColor[0];
    _color[1] = tempColor[1];
    _color[2] = tempColor[2];
    _color[3] = tempColor[3];
    _color[4] = tempColor[4];
    _color[5] = tempColor[5];

    _orientation[0] = FACE_PATTERN[_color.indexOf('W')];
    _orientation[1] = FACE_PATTERN[_color.indexOf('R')];
    _orientation[2] = FACE_PATTERN[_color.indexOf('G')];
    _orientation[3] = FACE_PATTERN[_color.indexOf('Y')];
    _orientation[4] = FACE_PATTERN[_color.indexOf('O')];
    _orientation[5] = FACE_PATTERN[_color.indexOf('B')];
}

char Cube::decode(char face)
{
    switch (face)
    {
    case 'U':
        return _orientation[0]; // ascii table
    case 'u':
        return _orientation[0] + 32;
    case 'V':
        return _orientation[0] + 1;
    case 'R':
        return _orientation[1];
    case 'r':
        return _orientation[1] + 32;
    case 'S':
        return _orientation[1] + 1;
    case 'F':
        return _orientation[2];
    case 'f':
        return _orientation[2] + 32;
    case 'G':
        return _orientation[2] + 1;
    case 'D':
        return _orientation[3];
    case 'd':
        return _orientation[3] + 32;
    case 'E':
        return _orientation[3] + 1;
    case 'L':
        return _orientation[4];
    case 'l':
        return _orientation[4] + 32;
    case 'M':
        return _orientation[4] + 1;
    case 'B':
        return _orientation[5];
    case 'b':
        return _orientation[5] + 32;
    case 'C':
        return _orientation[5] + 1;
    }
}

void Cube::makeMove(char move)
{
    switch (move)
    {
    case 'U':
        Moves::Uu();
        tempColor[0] = _color[3];
        tempColor[1] = _color[2];
        tempColor[2] = _color[1];
        tempColor[3] = _color[0];
        tempColor[4] = _color[5];
        tempColor[5] = _color[4];
        break;

    case 'u':
        Moves::Up();
        tempColor[0] = _color[3];
        tempColor[1] = _color[5];
        tempColor[2] = _color[4];
        tempColor[3] = _color[0];
        tempColor[4] = _color[2];
        tempColor[5] = _color[1];
        break;

    case 'V':
        Moves::U2();
        tempColor[0] = _color[3];
        tempColor[1] = _color[4];
        tempColor[2] = _color[2];
        tempColor[3] = _color[0];
        tempColor[4] = _color[1];
        tempColor[5] = _color[5];
        break;

    case 'R':
        Moves::Rr();
        tempColor[0] = _color[4];
        tempColor[1] = _color[5];
        tempColor[2] = _color[0];
        tempColor[3] = _color[1];
        tempColor[4] = _color[2];
        tempColor[5] = _color[3];
        break;

    case 'r':
        Moves::Rp();
        tempColor[0] = _color[4];
        tempColor[1] = _color[2];
        tempColor[2] = _color[3];
        tempColor[3] = _color[1];
        tempColor[4] = _color[5];
        tempColor[5] = _color[0];
        break;

    case 'S':
        Moves::R2();
        tempColor[0] = _color[4];
        tempColor[1] = _color[3];
        tempColor[2] = _color[5];
        tempColor[3] = _color[1];
        tempColor[4] = _color[0];
        tempColor[5] = _color[2];
        break;

    case 'F':
        Moves::Ff();
        tempColor[0] = _color[5];
        tempColor[1] = _color[3];
        tempColor[2] = _color[1];
        tempColor[3] = _color[2];
        tempColor[4] = _color[0];
        tempColor[5] = _color[4];
        break;

    case 'f':
        Moves::Fp();
        tempColor[0] = _color[5];
        tempColor[1] = _color[0];
        tempColor[2] = _color[4];
        tempColor[3] = _color[2];
        tempColor[4] = _color[3];
        tempColor[5] = _color[1];
        break;

    case 'G':
        Moves::F2();
        tempColor[0] = _color[5];
        tempColor[1] = _color[4];
        tempColor[2] = _color[3];
        tempColor[3] = _color[2];
        tempColor[4] = _color[1];
        tempColor[5] = _color[0];
        break;

    case 'D':
        Moves::Dd();
        tempColor[0] = _color[0];
        tempColor[1] = _color[5];
        tempColor[2] = _color[1];
        tempColor[3] = _color[3];
        tempColor[4] = _color[2];
        tempColor[5] = _color[4];
        break;

    case 'd':
        Moves::Dp();
        tempColor[0] = _color[0];
        tempColor[1] = _color[2];
        tempColor[2] = _color[4];
        tempColor[3] = _color[3];
        tempColor[4] = _color[5];
        tempColor[5] = _color[1];
        break;

    case 'E':
        Moves::D2();
        tempColor[0] = _color[0];
        tempColor[1] = _color[4];
        tempColor[2] = _color[5];
        tempColor[3] = _color[3];
        tempColor[4] = _color[1];
        tempColor[5] = _color[2];
        break;

    case 'L':
        Moves::Ll();
        tempColor[0] = _color[1];
        tempColor[1] = _color[5];
        tempColor[2] = _color[3];
        tempColor[3] = _color[4];
        tempColor[4] = _color[2];
        tempColor[5] = _color[0];
        break;

    case 'l':
        Moves::Lp();
        tempColor[0] = _color[1];
        tempColor[1] = _color[2];
        tempColor[2] = _color[0];
        tempColor[3] = _color[4];
        tempColor[4] = _color[5];
        tempColor[5] = _color[3];
        break;

    case 'M':
        Moves::L2();
        tempColor[0] = _color[1];
        tempColor[1] = _color[0];
        tempColor[2] = _color[5];
        tempColor[3] = _color[4];
        tempColor[4] = _color[3];
        tempColor[5] = _color[2];
        break;

    case 'B':
        Moves::Bb();
        tempColor[0] = _color[2];
        tempColor[1] = _color[0];
        tempColor[2] = _color[1];
        tempColor[3] = _color[5];
        tempColor[4] = _color[3];
        tempColor[5] = _color[4];
        break;

    case 'b':
        Moves::Bp();
        tempColor[0] = _color[2];
        tempColor[1] = _color[3];
        tempColor[2] = _color[4];
        tempColor[3] = _color[5];
        tempColor[4] = _color[0];
        tempColor[5] = _color[1];
        break;

    case 'C':
        Moves::B2();
        tempColor[0] = _color[2];
        tempColor[1] = _color[4];
        tempColor[2] = _color[0];
        tempColor[3] = _color[5];
        tempColor[4] = _color[1];
        tempColor[5] = _color[3]; 
        break;
    }
    updateOrientation();
}