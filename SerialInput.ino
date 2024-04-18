#include <Servo.h>

const int flexPin = A1;      // Pin connected to voltage divider output
const int f1_pin = 11;
const int f2_pin = 6;
const int f3_pin = 10;
const int t_pin = 5;
const int p_pin = 3;
const int ts_pin = 9;

Servo f1;
Servo f2;
Servo f3;
Servo t;
Servo p;

int a1 = 0;
int a2 = 0;
int a3 = 0;
int a4 = 0;
int a5 = 0;
Servo ts;

// Change these constants according to your project's design
const float VCC = 5;      // voltage at Ardunio 5V line
const float R_DIV = 200000.0;  // resistor used to create a voltage divider
const float flatResistance = 27000.0; // resistance when flat, Sensor 1: T1-50, T2-45, T3-35
const float bendResistance = 77000.0;  // resistance at 90 deg, Retesting, max hit at 65, angle<90, T3-50 t4 - 55

void setup() {
  Serial.begin(9600);
  pinMode(flexPin, INPUT);

  f1.attach(f1_pin);
  f2.attach(f2_pin);
  f3.attach(f3_pin);
  t.attach(t_pin);
  ts.attach(ts_pin);
  p.attach(p_pin);
//  Serial.begin(9600);
  f1.write(0);
  f2.write(0);
  f3.write(0);
  t.write(90);
  ts.write(75); //works, range is from 45 to 75
  p.write(0); //works
  
}

void loop() {

  if (Sreial.available())
  {
    String input = Srial.readStringUntil('\n');

    int servoAngle[6];

    for (int i = 0; i < 6; i++)
    {
        int commaIndex = input.indexOf(',');
        if(commandIndex > -1)
        {
            servoAngles[i] = input.substring(0, commaIndex).toInt();
            input = input.substring(commaIndex + 1);
        } else
        {
            servoAngles[i] = input.toInt();
        }

        if(servoAngles[i] < 0)
        {
            servoAngles[i] = 0;
        }
        else if (servoAngles[i] > 180)
        {
            servoAngles[i] = 180;
        
        }
    }
   
    //pin assignments 
    //first control digit
    //second control digit
    //third control digit
   f1.write(servoAngles[0]);
   f2.write(servoAngles[1]);
   f3.write(servoAngles[2]);
    t.write(servoAngles[3]);
    ts.write(servoAngles[4]);
    p.write(servoAngles[5]);
  }



   
  delay(500);
}