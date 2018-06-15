/* 3D robotic arm  by Mr Jefferson 105
 *  https://www.youtube.com/user/MrJefferson105
 *  
 *   The following code was design to enable studets or
     hobiiest to be able to control several servos with
     a bluetooth module.

 *   The bluetooth module : HC06
 *   link : http://www.icstation.com/products_new.php

  *  you will get a discount is you use this code :

                 Code:105ics
                 Discount Amount: 10%
                 Max Use: 1 （one for per customer）
                 No Min Order
                 Started Date: 16th,August 2016
                 Ended Date: 16th,November 2016
*/



#include <Servo.h>
// name of object to controll each servo
Servo myservo1;  // up and down
Servo myservo2;  // claw
Servo myservo3; // turn (left right )
Servo myservo4;


char unChar;


// we used this to be able to get a stream of variables  to be read by the arduino from the app
String readString;

void setup() {
  // These pins have to be PWM pins for the servos to work.
  myservo1.attach(5);
  myservo2.attach(6);
  myservo3.attach(7);
  myservo4.attach(3);
  Serial.begin(9600); //inisialisation of the serial
}

void loop() {
  if (Serial.available()) {  // it identifies the firs character in serial port
    unChar = Serial.read();

    if (unChar == 'A') { // This says that if "A" is detected then switch ON motor 1
      motor1();
    }

    if (unChar == 'B') { // This says that if "B is detected then switch ON motor 2
      motor2();
    }

    if (unChar == 'C') { // This says that if "Cis detected then switch ON motor 3
      motor3();
    }
    if (unChar == 'D') { // This says that if "Cis detected then switch ON motor 4
      motor4();
    }

  }
}

void motor1() {
  delay(5);
  while (Serial.available()) { //Now the numerical data of the angle of the servomotor is received
    //delayMicroseconds(100);
    char c = Serial.read();  // Se leen los caracteres que ingresan por el puerto
    readString += c;         //each character builds in a string
  }
  if (readString.length() > 0) {  //the length of the string is verified
    Serial.println(readString.toInt());  //Now we send data to serial and servos
    myservo1.write(readString.toInt());
    readString = ""; // Clear string
  }
}

void motor2() {
  delay(5);
  while (Serial.available()) {
    //delayMicroseconds(100);
    char c = Serial.read();
    readString += c;
  }
  if (readString.length() > 0) {
    Serial.println(readString.toInt());
    myservo2.write(readString.toInt());
    readString = "";
  }
}

void motor3() {
  delay(5);
  while (Serial.available()) {
    //delayMicroseconds(100);
    char c = Serial.read();
    readString += c;
  }
  if (readString.length() > 0) {
    Serial.println(readString.toInt());
    myservo3.write(readString.toInt());
    readString = "";
  }
}
void motor4() {
  delay(5);
  while (Serial.available()) {
    //delayMicroseconds(100);
    char c = Serial.read();
    readString += c;
  }
  if (readString.length() > 0) {
    Serial.println(readString.toInt());
    myservo4.write(readString.toInt());
    readString = "";
  }
}

