#include <Arduino.h>
#include <Servo.h>

#define RED 11
#define GREEN 12
#define BLUE 13
#define X A4
#define Y A5
#define SERVO D0
#define MTR1 2
#define MTR2 3

// DECLARE SERVO OBJECT
Servo steering;

// DECLARE VARIABLES
int power;
int steerAngle;

// FUNCTION PROTOTYPES
void driveMotor(int);
void steer(int);

void setup() {
  // SETUP LEDS
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);

  // SETUP SERIAL MONITOR
  Serial.begin(9600);

  // SETUP SERVO
  steering.attach(SERVO);

  // SETUP JOYSTICK PINS
  pinMode(X, INPUT);
  pinMode(Y, INPUT);
  
  // DEFINE MOTOR PINS AS OUTPUTS
  pinMode(MTR1, OUTPUT);
  pinMode(MTR2, OUTPUT);
}

void loop() {
  driveMotor(analogRead(Y));
  steer(analogRead(X));
}

void driveMotor(int val){
  Serial.println(val);

  if(val > 540){
    power = map(val, 541, 1018, 0, 255);
    analogWrite(MTR2, 0);
    analogWrite(MTR1, power);
    digitalWrite(GREEN, LOW);
    digitalWrite(RED, HIGH);
  } else if(val < 500){
    power = map(val, 500, 0, 0, 255);
    analogWrite(MTR1, 0);
    analogWrite(MTR2, power);
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, LOW);
  } else{
    analogWrite(MTR1, 0);
    analogWrite(MTR2, 0);
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, HIGH);
  }
}

void steer(int val){
  steerAngle = map(val, 0, 1016, 0, 180);
  steering.write(steerAngle);
}