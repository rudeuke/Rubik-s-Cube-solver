#include <Servo.h>

Servo rotationServo;                    //main rotation servo (MG 996R)
const int rotationServoPin = 9;
const int rotationServoAngle1 = 19;
const int rotationServoAngle2 = 115;

Servo blockServo;                       //2 upper layers block servo (SG90)
const int blockServoPin = 10;
const int blockServoAngle1 = 50;
const int blockServoAngle2 = 135;

Servo flipServo;                        //flip servo (MG 996R)
const int flipServoPin = 11;
const int flipServoAngle1 = 15;
const int flipServoAngle2 = 75;


int data = 0;
const int waitTime = 300;
const int waitTimeLong = 600;

// sequence of moves
String algorithm = "EVGCSM";            // temp sequence to make crosses

// orientation of cube --- orientation[color] = face
// COLOR     INDEX   STARTING FACE
// White      0       Up
// Red        1       Right
// Green      2       Front
// Yellow     3       Down
// Orange     4       Left
// Blue       5       Back
char orientation[] = {'U', 'R', 'F', 'D', 'L', 'B'};

const char facePattern[] = {'U', 'R', 'F', 'D', 'L', 'B'};

String color = "WRGYOB";
char tempColor[7];








void updateOrientation(){

  orientation[0] = facePattern[color.indexOf('W')];
  orientation[1] = facePattern[color.indexOf('R')];
  orientation[2] = facePattern[color.indexOf('G')];
  orientation[3] = facePattern[color.indexOf('Y')];
  orientation[4] = facePattern[color.indexOf('O')];
  orientation[5] = facePattern[color.indexOf('B')];
}





// elementary operations
void turnClockwise(int numberOfTimes){                        // D

  numberOfTimes=numberOfTimes%4;

  for(int i=0; i<numberOfTimes; i++){                         // repeat x times

    for(int j=blockServoAngle1; j<blockServoAngle2; j++){     // for slower lowering of the block module
      delay(5);
      blockServo.write(j);
    }

    delay(waitTime);
    rotationServo.write(rotationServoAngle2+14);
    delay(waitTimeLong);
    rotationServo.write(rotationServoAngle2);
    delay(waitTime);
    blockServo.write(blockServoAngle1);
    delay(waitTime);
    rotationServo.write(rotationServoAngle1);
    delay(waitTime);

    // tempColor[0] = color[0];
    tempColor[1] = color[5];
    tempColor[2] = color[1];
    // tempColor[3] = color[3];
    tempColor[4] = color[2];
    tempColor[5] = color[4];

    // color[0] = tempColor[0];
    color[1] = tempColor[1];
    color[2] = tempColor[2];
    // color[3] = tempColor[3];
    color[4] = tempColor[4];
    color[5] = tempColor[5];
  }
  updateOrientation();
}

void turnCounterclockwise(int numberOfTimes){                 // D'

  numberOfTimes=numberOfTimes%4;

  for(int i=0; i<numberOfTimes; i++){                         // repeat x times

    rotationServo.write(rotationServoAngle2);
    delay(waitTime);

    for(int j=blockServoAngle1; j<blockServoAngle2; j++){     // for slower lowering of the block module
      delay(5);
      blockServo.write(j);
    }
    
    delay(waitTime);
    rotationServo.write(rotationServoAngle1-5);
    delay(waitTimeLong);
    rotationServo.write(rotationServoAngle1);
    delay(waitTime);
    blockServo.write(blockServoAngle1);
    delay(waitTime);

    // tempColor[0] = color[0];
    tempColor[1] = color[2];
    tempColor[2] = color[4];
    // tempColor[3] = color[3];
    tempColor[4] = color[5];
    tempColor[5] = color[1];

    // color[0] = tempColor[0];
    color[1] = tempColor[1];
    color[2] = tempColor[2];
    // color[3] = tempColor[3];
    color[4] = tempColor[4];
    color[5] = tempColor[5];
  }
  updateOrientation();
}

void flipBack(int numberOfTimes){

  numberOfTimes=numberOfTimes%4;
  
  for(int i=0; i<numberOfTimes; i++){                         // repeat x times
    
    for(int j=flipServoAngle1; j<flipServoAngle2; j++){       // for slower movement of flip arm
      delay(8);
      flipServo.write(j);
    }
    flipServo.write(flipServoAngle1);
    delay(waitTime);

    tempColor[0] = color[2];
    // tempColor[1] = color[1];
    tempColor[2] = color[3];
    tempColor[3] = color[5];
    // tempColor[4] = color[4];
    tempColor[5] = color[0];

    color[0] = tempColor[0];
    // color[1] = tempColor[1];
    color[2] = tempColor[2];
    color[3] = tempColor[3];
    // color[4] = tempColor[4];
    color[5] = tempColor[5];  
  }
  updateOrientation();
}

void flipRight(int numberOfTimes){

  numberOfTimes=numberOfTimes%4;

  rotationServo.write(rotationServoAngle2);
  delay(waitTime);

  for(int i=0; i<numberOfTimes; i++){                         // repeat x times
    
    for(int j=flipServoAngle1; j<flipServoAngle2; j++){       // for slower movement of flip arm
      delay(8);
      flipServo.write(j);
    }
    flipServo.write(flipServoAngle1);
    delay(waitTime);

    tempColor[0] = color[4];
    tempColor[1] = color[0];
    // tempColor[2] = color[2];
    tempColor[3] = color[1];
    tempColor[4] = color[3];
    // tempColor[5] = color[5];

    color[0] = tempColor[0];
    color[1] = tempColor[1];
    // color[2] = tempColor[2];
    color[3] = tempColor[3];
    color[4] = tempColor[4];
    // color[5] = tempColor[5];
  }
  updateOrientation();

  rotationServo.write(rotationServoAngle1);
  delay(waitTime);
}










// cube moves
void Fr(){
  flipBack(3);
  turnClockwise(1);
}

void Fr2(){
  flipBack(3);
  turnClockwise(2);
}

void Frp(){
  flipBack(3);
  turnCounterclockwise(1);
}

void R(){
  flipRight(1);
  turnClockwise(1);
}

void R2(){
  flipRight(1);
  turnClockwise(2);
}

void Rp(){
  flipRight(1);
  turnCounterclockwise(1);
}

void U(){
  flipBack(2);
  turnClockwise(1);
}

void U2(){
  flipBack(2);
  turnClockwise(2);
}

void Up(){
  flipBack(2);
  turnCounterclockwise(1);
}

void L(){
  flipRight(3);
  turnClockwise(1);
}

void L2(){
  flipRight(3);
  turnClockwise(2);
}

void Lp(){
  flipRight(3);
  turnCounterclockwise(1);
}

void B(){
  flipBack(1);
  turnClockwise(1);
}

void B2(){
  flipBack(1);
  turnClockwise(2);
}

void Bp(){
  flipBack(1);
  turnCounterclockwise(1);
}

void D(){
  turnClockwise(1);
}

void D2(){
  turnClockwise(2);
}

void Dp(){
  turnCounterclockwise(1);
}










// logic
char decode(char face){

  switch(face){
    case 'U': return orientation[0];      // ascii table
    case 'u': return orientation[0]+32;
    case 'V': return orientation[0]+1;
    case 'R': return orientation[1];
    case 'r': return orientation[1]+32;
    case 'S': return orientation[1]+1;
    case 'F': return orientation[2];
    case 'f': return orientation[2]+32;
    case 'G': return orientation[2]+1;
    case 'D': return orientation[3];
    case 'd': return orientation[3]+32;
    case 'E': return orientation[3]+1;
    case 'L': return orientation[4];
    case 'l': return orientation[4]+32;
    case 'M': return orientation[4]+1;
    case 'B': return orientation[5];
    case 'b': return orientation[5]+32;
    case 'C': return orientation[5]+1;
    default:  return 'a';                 // error
  }
}

void makeMove(char move){

  switch(move){
    case 'F':
      Fr();
    break;

    case 'f':
      Frp();
    break;

    case 'G':
      Fr2();
    break;

    case 'R':
      R();
    break;

    case 'r':
      Rp();
    break;

    case 'S':
      R2();
    break;

    case 'U':
      U();
    break;

    case 'u':
      Up();
    break;

    case 'V':
      U2();
    break;

    case 'L':
      L();
    break;

    case 'l':
      Lp();
    break;

    case 'M':
      L2();
    break;

    case 'B':
      B();
    break;

    case 'b':
      Bp();
    break;

    case 'C':
      B2();
    break;

    case 'D':
      D();
    break;

    case 'd':
      Dp();
    break;

    case 'E':
      D2();
    break;    
  }
}

void solve(String moves){

  int numberOfMoves = moves.length();

  Serial.print("moves: ");
  for(int i=0; i<numberOfMoves; i++){
    Serial.print(moves[i]);
    Serial.print(" ");        
  }

  // Serial.println("");

  // Serial.print("orientation: ");
  // for(int j=0; j<6; j++){
  //   Serial.print(orientation[j]);
  //   Serial.print(" "); 
  // }

  // Serial.println("");




  for(int i=0; i<numberOfMoves; i++){

    // Serial.println("");

    // Serial.print("next move: ");
    // Serial.print(moves[i]);

    // Serial.println("");

    // Serial.print("orientation: ");      //for debugging
    // for(int j=0; j<6; j++){
    //   Serial.print(orientation[j]);
    //   Serial.print(" "); 
    // }

    // Serial.println("");

    // Serial.print("after decode: ");
    // Serial.print(decode(moves[i]));
    
    // Serial.println("");

    char nextMove = decode(moves[i]);
    makeMove(nextMove);
  }
}










void setup() {
  Serial.begin(9600);
    
  rotationServo.attach(rotationServoPin);
  rotationServo.write(rotationServoAngle1);
  
  blockServo.attach(blockServoPin);
  blockServo.write(blockServoAngle1);

  flipServo.attach(flipServoPin);
  flipServo.write(flipServoAngle1);
}





void loop() {

  if(Serial.available() > 0){     //testing
    data=Serial.read();
    Serial.println(data);

    if(data==49){

      solve(algorithm);
      // flipBack(1);

    }
    else if(data==50){

      // flipRight(1);

    }

    data=0;
  }
}