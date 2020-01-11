const int LIGHTTHRESHOLD = 200; // calibrate 

int motorIn1 = 2;
int motorEnA = 3;
int motorIn2 = 4;
int motorEnB = 5;
int motorIn3 = 6;
int motorIn4 = 7;
int prF = A0;
int prL = A1;
int prR = A2; 


int leftMotorDir = {1,2};
int rightMotorDir = {3,4};   

int turnSignalL = 12;
int turnSignalR = 13;


int serialInput = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(motorEnA,OUTPUT); //initialize pins 
pinMode(motorEnA,OUTPUT);
pinMode(motorIn1, OUTPUT);
pinMode(motorIn2, OUTPUT);
pinMode(motorIn3, OUTPUT);
pinMode(motorIn4, OUTPUT);

digitalWrite(motorIn1, HIGH); //set directions 
digitalWrite(motorIn2, LOW);
digitalWrite(motorIn3, HIGH);
digitalWrite(motorIn4, LOW);

pinMode(turnSignalL, OUTPUT);
pinMode(turnSignalR, OUTPUT);


Serial.begin(9600); //begin serial connection for testing 

}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available() > 0) 
serialInput = Serial.parseInt();
if (serialInput > 0){
analogWrite(motorEnA, serialInput);
analogWrite(motorEnB, serialInput);}

}


Bill of functions

Global Variables
Int turnAngleCourseCorrectionL
Int turnAngleCourseCorrectionR
 

turn(int angle){
  // negative angles mean left 
  
}


adjustLR(bool hitLeft){
  if(hitLeft){
  turn(*right*);
} else {
  turn(*left*);
}
}



void setup() {
  //sense_front is controlled by a function that sets the bool depending on whether the photoresistor reading exceeds the thing or not.
 
  bool sense_front = false;
  bool sense_left = false;
  bool sense_right = false;

int currentTime = 0;
  startmillis = millis(); //starts millis. Don't call this var

void adjustLeft(){
  //hits the left wall and adjusts towards the right
  turn(10);
  currentTime = millis();
  while (millis() < (currentTime + 60)){
  goForward();
  }
  turn(-8);
}

void adjustRight(){
  //hits the right wall and adjtusts towards the left
  turn(-10);
   currentTime = millis();
  while (millis() < (currentTime + 60)){
  goForward();
  }
  turn(8);
}

void goForward(){
  analogWrite(motorEnA, 255);
  analogWrite(motorEnB, 255);
}

void cornerTurn(){
  turn(90);
  currentTime = millis();
  while ((sense_front == false) && (millis < (currentTime + 1000)){
  goForward();
  }
  if (sense_front == true){
  turn(180);
  }
}

void loop() {
  while ((sense_front == false) && (sense_left == false) && (sense_right == false)){
  goForward();
  }
  if ((sense_front == false) && (sense_left == true) && (sense_right == false)){
  adjustLeft();
  }
  if ((sense_front == false) && (sense_left == false) && (sense_right == true)){
  adjustRight();
  }
  if (sense_front == true){
  cornerTurn();
  }
}
 
int leftMotorDir = {1,2};
int rightMotorDir = {3,4};  


const int MSTOCOMPLETEREVOLUTION = 1000; //change this to what it really should be;

void turn(int angle){
  int turnDelayTime = (abs(angle)/360) * MSTOCOMPLETEREVOLUTION;
  if(angle < 0){ //left turn
    //left motor moves backwards
    //right motor moves forwards
    changeMotorDir(leftMotor, false);
    changeMotorDir(rightMotor, true);
    digitalWrite(turnSignalL, HIGH)
  } else { //right turn
  //left motor moves forwards
    //right motor moves backwards
    changeMotorDir(leftMotor, true);
    changeMotorDir(rightMotor, false);
    digitalWrite(turnSignalR, HIGH)
  }
  powerMotors(255);
  delay(turnDelayTime); //turn for desired amount
  digitalWrite(turnSignalL, LOW);
  digitalWrite(turnSignalR, LOW);
}


void powerMotors(int power){
  analogWrite(motorEnA, power);
  analogWrite(motorEnB, power);
}
void changeMotorDir(int motorIn[]; boolean forward){
  if (forward){
    digitalWrite(motorIn[0], HIGH);
    digitalWrite(motorIn[1], LOW);
  } else {
    digitalWrite(motorIn[0], LOW);
    digitalWrite(motorIn[1], HIGH);
  }
}


void checkLightThresholds(){
  sense_front = (analogRead(prF) > LIGHTTHRESHOLD);
  sense_left = (analogRead(prlL) > LIGHTTHRESHOLD);
  sense_right = (analogRead(prR) > LIGHTTHRESHOLD);
}
