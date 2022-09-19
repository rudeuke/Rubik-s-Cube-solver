#ifndef Cube_h
#define Cube_h

class Cube
{
public:
    void scan();
    void solve(String moves);

private:
    char _orientation[6] = {'U', 'R', 'F', 'D', 'L', 'B'};
    String _color = "WRGYOB";

    void updateOrientation();
    char decode(char face);
    void makeMove(char move);
};

#endif

// orientation of cube --- _orientation[_color] = face
// COLOR     INDEX   STARTING FACE
// White      0       Up
// Red        1       Right
// Green      2       Front
// Yellow     3       Down
// Orange     4       Left
// Blue       5       Back