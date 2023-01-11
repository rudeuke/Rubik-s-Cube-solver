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