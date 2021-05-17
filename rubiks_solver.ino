#include <Servo.h>

Servo rotationServo;                    //main rotation servo (MG 996R)
const int rotationServoPin = 9;
const int rotationServoAngle1 = 16;
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
int waitTime = 300;
int waitTimeLong = 600;

// sequence of moves
// char solution[] = {'E', 'V', 'G', 'C', 'S', 'M'};   // temp sequence to make crosses
char solution[] = {'C', 'd', 'f', 'L'}; //testing sequence

// orientation of cube --- orientation[color] = face
// COLOR     INDEX   STARTING FACE
// Orange     0       Front
// Green      1       Right
// White      2       Up
// Blue       3       Left
// Red        4       Back
// Yellow     5       Down
char orientation[] = {'F', 'R', 'U', 'L', 'B', 'D'};
char tempOrientation[7];










// elementary operations
void turnClockwise(int numberOfTimes){                        // D

  numberOfTimes=numberOfTimes%4;

  for(int i=0; i<numberOfTimes; i++){                         // repeat x times

    for(int j=blockServoAngle1; j<blockServoAngle2; j++){     // for slower lowering of the block module
      delay(5);
      blockServo.write(j);
    }

    delay(waitTime);
    rotationServo.write(rotationServoAngle2+10);
    delay(waitTimeLong);
    rotationServo.write(rotationServoAngle2);
    delay(waitTime);
    blockServo.write(blockServoAngle1);
    delay(waitTime);
    rotationServo.write(rotationServoAngle1);
    delay(waitTime);    
  }
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
  }
}

void flipBack(int numberOfTimes){

  numberOfTimes=numberOfTimes%4;
  
  for(int i=0; i<numberOfTimes; i++){                         // repeat x times
    
    for(int j=flipServoAngle1; j<flipServoAngle2; j++){       // for slower movement of flip arm
      delay(7);
      flipServo.write(j);
    }
    flipServo.write(flipServoAngle1);
    delay(waitTime);
  }
}

void flipRight(int numberOfTimes){

  rotationServo.write(rotationServoAngle2);
  delay(waitTime);
  flipBack(numberOfTimes);
  rotationServo.write(rotationServoAngle1);
  delay(waitTime);
}










// cube moves
void Fr(){
  flipBack(3);
  turnClockwise(1);
  
  //{'F', 'R', 'U', 'L', 'B', 'D'}
  //{'D', 'F', 'L', 'B', 'U', 'R'}
  tempOrientation[0] = orientation[5];
  tempOrientation[1] = orientation[0];
  tempOrientation[2] = orientation[3];
  tempOrientation[3] = orientation[4];
  tempOrientation[4] = orientation[2];
  tempOrientation[5] = orientation[1];

  orientation[0] = tempOrientation[0];
  orientation[1] = tempOrientation[1];
  orientation[2] = tempOrientation[2];
  orientation[3] = tempOrientation[3];
  orientation[4] = tempOrientation[4];
  orientation[5] = tempOrientation[5];
}

void Fr2(){
  flipBack(3);
  turnClockwise(2);

  //{'F', 'R', 'U', 'L', 'B', 'D'}
  //{'D', 'L', 'B', 'R', 'U', 'F'}
  tempOrientation[0] = orientation[5];
  tempOrientation[1] = orientation[3];
  tempOrientation[2] = orientation[4];
  tempOrientation[3] = orientation[1];
  tempOrientation[4] = orientation[2];
  tempOrientation[5] = orientation[0];

  orientation[0] = tempOrientation[0];
  orientation[1] = tempOrientation[1];
  orientation[2] = tempOrientation[2];
  orientation[3] = tempOrientation[3];
  orientation[4] = tempOrientation[4];
  orientation[5] = tempOrientation[5];
}

void Frp(){
  flipBack(3);
  turnCounterclockwise(1);

  //{'F', 'R', 'U', 'L', 'B', 'D'}
  //{'D', 'B', 'R', 'F', 'U', 'L'}
  tempOrientation[0] = orientation[5];
  tempOrientation[1] = orientation[4];
  tempOrientation[2] = orientation[1];
  tempOrientation[3] = orientation[0];
  tempOrientation[4] = orientation[2];
  tempOrientation[5] = orientation[3];

  orientation[0] = tempOrientation[0];
  orientation[1] = tempOrientation[1];
  orientation[2] = tempOrientation[2];
  orientation[3] = tempOrientation[3];
  orientation[4] = tempOrientation[4];
  orientation[5] = tempOrientation[5];
}

void R(){
  flipRight(1);
  turnClockwise(1);

  //{'F', 'R', 'U', 'L', 'B', 'D'}
  //{'L', 'D', 'F', 'U', 'R', 'B'}
  tempOrientation[0] = orientation[3];
  tempOrientation[1] = orientation[5];
  tempOrientation[2] = orientation[0];
  tempOrientation[3] = orientation[2];
  tempOrientation[4] = orientation[1];
  tempOrientation[5] = orientation[4];

  orientation[0] = tempOrientation[0];
  orientation[1] = tempOrientation[1];
  orientation[2] = tempOrientation[2];
  orientation[3] = tempOrientation[3];
  orientation[4] = tempOrientation[4];
  orientation[5] = tempOrientation[5];
}

void R2(){
  flipRight(1);
  turnClockwise(2);

  //{'F', 'R', 'U', 'L', 'B', 'D'}
  //{'B', 'D', 'L', 'U', 'F', 'R'}
  tempOrientation[0] = orientation[4];
  tempOrientation[1] = orientation[5];
  tempOrientation[2] = orientation[3];
  tempOrientation[3] = orientation[2];
  tempOrientation[4] = orientation[0];
  tempOrientation[5] = orientation[1];

  orientation[0] = tempOrientation[0];
  orientation[1] = tempOrientation[1];
  orientation[2] = tempOrientation[2];
  orientation[3] = tempOrientation[3];
  orientation[4] = tempOrientation[4];
  orientation[5] = tempOrientation[5];
}

void Rp(){
  flipRight(1);
  turnCounterclockwise(1);

  //{'F', 'R', 'U', 'L', 'B', 'D'}
  //{'R', 'D', 'B', 'U', 'L', 'F'}
  tempOrientation[0] = orientation[1];
  tempOrientation[1] = orientation[5];
  tempOrientation[2] = orientation[4];
  tempOrientation[3] = orientation[2];
  tempOrientation[4] = orientation[3];
  tempOrientation[5] = orientation[0];

  orientation[0] = tempOrientation[0];
  orientation[1] = tempOrientation[1];
  orientation[2] = tempOrientation[2];
  orientation[3] = tempOrientation[3];
  orientation[4] = tempOrientation[4];
  orientation[5] = tempOrientation[5];
}

void U(){
  flipBack(2);
  turnClockwise(1);

  //{'F', 'R', 'U', 'L', 'B', 'D'}
  //{'R', 'F', 'D', 'B', 'L', 'U'}
  tempOrientation[0] = orientation[1];
  tempOrientation[1] = orientation[0];
  tempOrientation[2] = orientation[5];
  tempOrientation[3] = orientation[4];
  tempOrientation[4] = orientation[3];
  tempOrientation[5] = orientation[2];

  orientation[0] = tempOrientation[0];
  orientation[1] = tempOrientation[1];
  orientation[2] = tempOrientation[2];
  orientation[3] = tempOrientation[3];
  orientation[4] = tempOrientation[4];
  orientation[5] = tempOrientation[5];
}

void U2(){
  flipBack(2);
  turnClockwise(2);

  //{'F', 'R', 'U', 'L', 'B', 'D'}
  //{'F', 'L', 'D', 'R', 'B', 'U'}
  tempOrientation[0] = orientation[0];
  tempOrientation[1] = orientation[3];
  tempOrientation[2] = orientation[5];
  tempOrientation[3] = orientation[1];
  tempOrientation[4] = orientation[4];
  tempOrientation[5] = orientation[2];

  orientation[0] = tempOrientation[0];
  orientation[1] = tempOrientation[1];
  orientation[2] = tempOrientation[2];
  orientation[3] = tempOrientation[3];
  orientation[4] = tempOrientation[4];
  orientation[5] = tempOrientation[5];
}

void Up(){
  flipBack(2);
  turnCounterclockwise(1);

  //{'F', 'R', 'U', 'L', 'B', 'D'}
  //{'L', 'B', 'D', 'F', 'R', 'U'}
  tempOrientation[0] = orientation[3];
  tempOrientation[1] = orientation[4];
  tempOrientation[2] = orientation[5];
  tempOrientation[3] = orientation[0];
  tempOrientation[4] = orientation[1];
  tempOrientation[5] = orientation[2];

  orientation[0] = tempOrientation[0];
  orientation[1] = tempOrientation[1];
  orientation[2] = tempOrientation[2];
  orientation[3] = tempOrientation[3];
  orientation[4] = tempOrientation[4];
  orientation[5] = tempOrientation[5];
}

void L(){
  flipRight(3);
  turnClockwise(1);

  //{'F', 'R', 'U', 'L', 'B', 'D'}
  //{'L', 'U', 'B', 'D', 'R', 'F'}
  tempOrientation[0] = orientation[3];
  tempOrientation[1] = orientation[2];
  tempOrientation[2] = orientation[4];
  tempOrientation[3] = orientation[5];
  tempOrientation[4] = orientation[1];
  tempOrientation[5] = orientation[0];

  orientation[0] = tempOrientation[0];
  orientation[1] = tempOrientation[1];
  orientation[2] = tempOrientation[2];
  orientation[3] = tempOrientation[3];
  orientation[4] = tempOrientation[4];
  orientation[5] = tempOrientation[5];
}

void L2(){
  flipRight(3);
  turnClockwise(2);

  //{'F', 'R', 'U', 'L', 'B', 'D'}
  //{'B', 'U', 'R', 'D', 'F', 'L'}
  tempOrientation[0] = orientation[4];
  tempOrientation[1] = orientation[2];
  tempOrientation[2] = orientation[1];
  tempOrientation[3] = orientation[5];
  tempOrientation[4] = orientation[0];
  tempOrientation[5] = orientation[3];

  orientation[0] = tempOrientation[0];
  orientation[1] = tempOrientation[1];
  orientation[2] = tempOrientation[2];
  orientation[3] = tempOrientation[3];
  orientation[4] = tempOrientation[4];
  orientation[5] = tempOrientation[5];
}

void Lp(){
  flipRight(3);
  turnCounterclockwise(1);

  //{'F', 'R', 'U', 'L', 'B', 'D'}
  //{'R', 'U', 'F', 'D', 'L', 'B'}
  tempOrientation[0] = orientation[1];
  tempOrientation[1] = orientation[2];
  tempOrientation[2] = orientation[0];
  tempOrientation[3] = orientation[5];
  tempOrientation[4] = orientation[3];
  tempOrientation[5] = orientation[4];

  orientation[0] = tempOrientation[0];
  orientation[1] = tempOrientation[1];
  orientation[2] = tempOrientation[2];
  orientation[3] = tempOrientation[3];
  orientation[4] = tempOrientation[4];
  orientation[5] = tempOrientation[5];
}

void B(){
  flipBack(1);
  turnClockwise(1);

  //{'F', 'R', 'U', 'L', 'B', 'D'}
  //{'U', 'F', 'R', 'B', 'D', 'L'}
  tempOrientation[0] = orientation[2];
  tempOrientation[1] = orientation[0];
  tempOrientation[2] = orientation[1];
  tempOrientation[3] = orientation[4];
  tempOrientation[4] = orientation[5];
  tempOrientation[5] = orientation[3];

  orientation[0] = tempOrientation[0];
  orientation[1] = tempOrientation[1];
  orientation[2] = tempOrientation[2];
  orientation[3] = tempOrientation[3];
  orientation[4] = tempOrientation[4];
  orientation[5] = tempOrientation[5];
}

void B2(){
  flipBack(1);
  turnClockwise(2);

  //{'F', 'R', 'U', 'L', 'B', 'D'}
  //{'U', 'L', 'F', 'R', 'D', 'B'}
  tempOrientation[0] = orientation[2];
  tempOrientation[1] = orientation[3];
  tempOrientation[2] = orientation[0];
  tempOrientation[3] = orientation[1];
  tempOrientation[4] = orientation[5];
  tempOrientation[5] = orientation[4];

  orientation[0] = tempOrientation[0];
  orientation[1] = tempOrientation[1];
  orientation[2] = tempOrientation[2];
  orientation[3] = tempOrientation[3];
  orientation[4] = tempOrientation[4];
  orientation[5] = tempOrientation[5];
}

void Bp(){
  flipBack(1);
  turnCounterclockwise(1);

  //{'F', 'R', 'U', 'L', 'B', 'D'}
  //{'U', 'B', 'L', 'F', 'D', 'R'}
  tempOrientation[0] = orientation[2];
  tempOrientation[1] = orientation[4];
  tempOrientation[2] = orientation[3];
  tempOrientation[3] = orientation[0];
  tempOrientation[4] = orientation[5];
  tempOrientation[5] = orientation[1];

  orientation[0] = tempOrientation[0];
  orientation[1] = tempOrientation[1];
  orientation[2] = tempOrientation[2];
  orientation[3] = tempOrientation[3];
  orientation[4] = tempOrientation[4];
  orientation[5] = tempOrientation[5];
}

void D(){
  turnClockwise(1);

  //{'F', 'R', 'U', 'L', 'B', 'D'}
  //{'L', 'F', 'U', 'B', 'R', 'D'}
  tempOrientation[0] = orientation[3];
  tempOrientation[1] = orientation[0];
  tempOrientation[2] = orientation[2];
  tempOrientation[3] = orientation[4];
  tempOrientation[4] = orientation[1];
  tempOrientation[5] = orientation[5];

  orientation[0] = tempOrientation[0];
  orientation[1] = tempOrientation[1];
  orientation[2] = tempOrientation[2];
  orientation[3] = tempOrientation[3];
  orientation[4] = tempOrientation[4];
  orientation[5] = tempOrientation[5];
}

void D2(){
  turnClockwise(2);

  //{'F', 'R', 'U', 'L', 'B', 'D'}
  //{'B', 'L', 'U', 'R', 'F', 'D'}
  tempOrientation[0] = orientation[4];
  tempOrientation[1] = orientation[3];
  tempOrientation[2] = orientation[2];
  tempOrientation[3] = orientation[1];
  tempOrientation[4] = orientation[0];
  tempOrientation[5] = orientation[5];

  orientation[0] = tempOrientation[0];
  orientation[1] = tempOrientation[1];
  orientation[2] = tempOrientation[2];
  orientation[3] = tempOrientation[3];
  orientation[4] = tempOrientation[4];
  orientation[5] = tempOrientation[5];
}

void Dp(){
  turnCounterclockwise(1);

  //{'F', 'R', 'U', 'L', 'B', 'D'}
  //{'R', 'B', 'U', 'F', 'L', 'D'}
  tempOrientation[0] = orientation[1];
  tempOrientation[1] = orientation[4];
  tempOrientation[2] = orientation[2];
  tempOrientation[3] = orientation[0];
  tempOrientation[4] = orientation[3];
  tempOrientation[5] = orientation[5];

  orientation[0] = tempOrientation[0];
  orientation[1] = tempOrientation[1];
  orientation[2] = tempOrientation[2];
  orientation[3] = tempOrientation[3];
  orientation[4] = tempOrientation[4];
  orientation[5] = tempOrientation[5];
}










// logic
char decode(char face){

  switch(face){
    case 'F': return orientation[0];      // ascii table
    case 'f': return orientation[0]+32;
    case 'G': return orientation[0]+1;
    case 'R': return orientation[1];
    case 'r': return orientation[1]+32;
    case 'S': return orientation[1]+1;
    case 'U': return orientation[2];
    case 'u': return orientation[2]+32;
    case 'V': return orientation[2]+1;
    case 'L': return orientation[3];
    case 'l': return orientation[3]+32;
    case 'M': return orientation[3]+1;
    case 'B': return orientation[4];
    case 'b': return orientation[4]+32;
    case 'C': return orientation[4]+1;
    case 'D': return orientation[5];
    case 'd': return orientation[5]+32;
    case 'E': return orientation[5]+1;
    default:  return 'a';
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

void solve(char solution[]){

  int numberOfMoves = strlen(solution);

  Serial.print("solution: ");
    for(int i=0; i<numberOfMoves; i++){
       Serial.print(solution[i]);
       Serial.print(" ");        
    }

  Serial.println("");

  Serial.print("orientation: ");
    for(int j=0; j<6; j++){
      Serial.print(orientation[j]);
      Serial.print(" "); 
    }

  Serial.println("");




  for(int i=0; i<numberOfMoves; i++){

    Serial.println("");

    Serial.print("next move: ");
    Serial.print(solution[i]);

    Serial.println("");

    Serial.print("orientation: ");      //for debugging
    for(int j=0; j<6; j++){
      Serial.print(orientation[j]);
      Serial.print(" "); 
    }

    Serial.println("");

    Serial.print("after decode: ");
    Serial.print(decode(solution[i]));
    
    Serial.println("");

    char nextMove = decode(solution[i]);
    makeMove(nextMove);


    delay(5000);
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

  delay(5000);
  solve(solution);
}





void loop() {

  // if(Serial.available() > 0){     //testing
  //   data=Serial.read();
  //   Serial.println(data);

  //   if(data==49){

  //     solve(solution);
  //     // Fr2();

  //   }
  //   else if(data==50){

  //     // B();

  //   }

  // data=0;

}