#include <PID_v1.h>
//Define Variables we'll be connecting to
double Input, Output1, Output2, Input1, Input2;
double Setpoint1 = 60;
double Setpoint2 = 0;
volatile double encoder0Pos = 0;
volatile double encoder1Pos = 0;
//Specify the links and initial tuning parameters
PID myLeftPID(&Input1, &Output1, &Setpoint1, 16, 0.268, 1, DIRECT);
PID myRightPID(&Input2, &Output2, &Setpoint2, 2, 0.5, 4, DIRECT);

void setup()
{
  pinMode(8, OUTPUT);  //PWM 1
  pinMode(9, OUTPUT);  //PWM 2
  pinMode(18, INPUT);
  pinMode(19, INPUT);
  digitalWrite(18, HIGH);       // turn on pullup resistors
  digitalWrite(19, HIGH);       // turn on pullup resistors
  attachInterrupt(4, doEncoder0, RISING);  // encoder pin on interrupt 0 - pin 2
  attachInterrupt(5, doEncoder1, RISING);  // encoder pin on interrupt 0 - pin 2  Serial.begin (9600);
  Serial.println("start");                // a personal quirk
  //initialize the variables we're linked to
  Input = analogRead(0);
  //turn the PID on
  myLeftPID.SetMode(AUTOMATIC);
  myRightPID.SetMode(AUTOMATIC);
}

void loop()
{
  Input = analogRead(0);
  Input1 = encoder0Pos;
  Input2 = encoder1Pos;
  myLeftPID.Compute();
  myRightPID.Compute();
  analogWrite(8, Output1);
  analogWrite(9, Output2);
}

void doEncoder0() {
  encoder0Pos++;
  Serial.println (Input1, DEC); Serial.print("\t");
  Serial.println (Input2, DEC);
}
void doEncoder1() {
  encoder1Pos++;
}
