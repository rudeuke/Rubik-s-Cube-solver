#ifndef ServoHandler_h
#define ServoHandler_h

class ServoHandler
{
public:
    static void turnClockwise(int numberOfTimes = 1);
    static void turnCounterclockwise(int numberOfTimes = 1);
    static void flipBack(int numberOfTimes = 1);
    static void flipRight(int numberOfTimes = 1);
    static void initialiseScan();

private:
    const static int _waitVeryShort = 50;
    const static int _waitShort = 150;
    const static int _waitMedium = 250;
    const static int _waitLong = 425;
    const static int _waitScan = 1200;

    static void blockCube();
    static void unblockCube();
    static void basePosition1(int offset = 0);
    static void basePosition2(int offset = 0);
    static void armFlip();
};

#endif