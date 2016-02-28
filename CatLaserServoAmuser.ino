/*------------------------------------------------------------------------------------------------------
                              Author : Evan Richinson aka MrRetupmoc42
               
Arduino Driven Cat Laser Positioner, Dual Axis
   
Febuary 27th 2016   : Stepper Code Imported and Updating for Timing / Postitional Data with Button Input Control
                      Stepper Homing, Drink Dispense Delay based on Position
                   
-------------------------------------------------------------------------------------------------------*/

#include <Servo.h>

Servo Xservo;  // create servo object to control a servo
Servo Yservo;  // create servo object to control a servo

int minx = 25;
int maxx = 55; //180
int speedx = 150;//275;//2000 / (maxx - minx);
int sleepx = 100;//500;//2000 / (maxx - minx);

int miny = 60;
int maxy = 90;

int Xpos = 0;    // variable to store the servo position
int Ypos = 0;    // variable to store the servo position

void setup() {
  Xservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Yservo.attach(10);  // attaches the servo on pin 9 to the servo object

  Serial.begin(9600);

  Movey(55);
}

void loop() {
  for (Ypos = miny; Ypos <= maxy; Ypos += 1) {
    Movey(Ypos); 
    
    for (Xpos = minx; Xpos <= maxx; Xpos += 1) { // goes from 0 degrees to 180 degrees
      Movex(Xpos);              // tell servo to go to position in variable 'pos'
      delay(speedx);                       // waits 15ms for the servo to reach the position
    }
    delay(sleepx);
    
    for (Xpos = maxx; Xpos >= minx; Xpos -= 1) { // goes from 180 degrees to 0 degrees
      Movex(Xpos);              // tell servo to go to position in variable 'pos'
      delay(speedx);                       // waits 15ms for the servo to reach the position
    }
    delay(sleepx);
  }

  for (Ypos = maxy; Ypos >= maxy; Ypos -= 1) {
    Movey(Ypos); 
    
    for (Xpos = maxx; Xpos >= minx; Xpos -= 1) { // goes from 180 degrees to 0 degrees
      Movex(Xpos);              // tell servo to go to position in variable 'pos'
      delay(speedx);                       // waits 15ms for the servo to reach the position
    }
    delay(sleepx);

    for (Xpos = minx; Xpos <= maxx; Xpos += 1) { // goes from 0 degrees to 180 degrees
      Movex(Xpos);              // tell servo to go to position in variable 'pos'
      delay(speedx);                       // waits 15ms for the servo to reach the position
    }
    delay(sleepx);
  }
}

void Movex(int x) {
  Xservo.write(x);
  Serial.println(x);
}

void Movey(int y) {
  Yservo.write(y);
  Serial.println(y);
}
