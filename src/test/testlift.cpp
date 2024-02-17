
#include <Arduino.h>
#include <Wire.h>
#include <ESP32Servo.h>

//15, 20, 4, 16, 17., 5, 18, 19, 21, 22, 23, 
//34, 35, 32, 33, 25, 26, 27, 14, 12, 13, 

Servo testLift1;
Servo testLift2;
Servo testLift3;
Servo testLift4;
Servo testLift5;
Servo testLift6;
Servo testLift7;
Servo testLift8;
Servo testLift9;
Servo testLift10;
Servo testLift11;
Servo testLift12;
Servo testLift13;
Servo testLift14;
Servo testLift15;
Servo testLift16;
Servo testLift17;
Servo testLift18;

// Define the testLift2 servo
void initLift() {
testLift1.attach(15);
testLift2.attach(2);
testLift3.attach(21);
testLift4.attach(4);
testLift5.attach(16);
testLift6.attach(17);
testLift7.attach(5);
testLift8.attach(18);
testLift9.attach(19);

testLift10.attach(13);
testLift11.attach(12);
testLift12.attach(14);
testLift13.attach(27);
testLift14.attach(26);
testLift15.attach(25);
testLift16.attach(33);
testLift17.attach(32);
testLift18.attach(35);
}

 
//LIFT ALL LEGS
void liftFunction(){
// LIMB 1 SEG 1
testLift1.write(90);
// //LIMB 1 SEG 2
 testLift2.write(135);
// //LIMB 1 SEG 3
 testLift3.write(125);

// //LIMB 2 SEG 1
testLift4.write(90);
// //LIMB 2 SEG 2
 testLift5.write(135);
// //LIMB 2 SEG 3
testLift6.write(125);

// LIMB 3 SEG 1
testLift7.write(90);
// //LIMB 3 SEG 2
 testLift8.write(135);
// //LIMB 3 SEG 3
testLift9.write(125);

// //LIMB 4 SEG 1
testLift10.write(90);
// //LIMB 4 SEG 2
testLift11.write(135);
// //LIMB 4 SEG 3
testLift12.write(125);

// //LIMB 5 SEG 1
testLift13.write(90);
// //LIMB 5 SEG 2
testLift14.write(135);
// //LIMB 5 SEG 3
testLift15.write(125);

// //LIMB 6 SEG 1
testLift16.write(90);
// //LIMB 6 SEG 2
 testLift17.write(135);
// //LIMB 6 SEG 3
testLift18.write(125);
 delay(200);
 }


