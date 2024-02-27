
#include <Arduino.h>
#include <Wire.h>
#include <ESP32Servo.h>

// //15, 20, 4, 16, 17., 5, 18, 19, 21, 22, 23, 
// //34, 35, 32, 33, 25, 26, 27, 14, 12, 13, 

Servo liftTest1;
Servo liftTest2;
Servo liftTest3;
Servo liftTest4;
Servo liftTest5;
Servo liftTest6;
Servo liftTest7;
Servo liftTest8;
Servo liftTest9;
Servo liftTest10;
Servo liftTest11;
Servo liftTest12;
Servo liftTest13;
Servo liftTest14;
Servo liftTest15;
Servo liftTest16;
Servo liftTest17;
Servo liftTest18;

// // Define the liftTest2 servo
void initLift() {
liftTest1.attach(15);
liftTest2.attach(2);
liftTest3.attach(21);
liftTest4.attach(4);
liftTest5.attach(16);
liftTest6.attach(17);
liftTest7.attach(5);
liftTest8.attach(18);
liftTest9.attach(19);

liftTest10.attach(13);
liftTest11.attach(12);
liftTest12.attach(14);
liftTest13.attach(27);
liftTest14.attach(26);
liftTest15.attach(25);
liftTest16.attach(33);
liftTest17.attach(32);
liftTest18.attach(35);
}

 void testLift(){
//LIMB 1 SEG 1
 liftTest1.write(90);
 //LIMB 1 SEG 2
liftTest2.write(90);
//LIMB 1 SEG 3
 liftTest3.write(90);

 //LIMB 2 SEG 1
 liftTest4.write(90);
 //LIMB 2 SEG 2
 liftTest5.write(90);
///LIMB 2 SEG 3
 liftTest6.write(90);

 //LIMB 3 SEG 1
liftTest7.write(90);
//LIMB 3 SEG 2
 liftTest8.write(90);
 //LIMB 3 SEG 3
 liftTest9.write(90);

//LIMB 4 SEG 1
liftTest10.write(90);
 //LIMB 4 SEG 2
 liftTest11.write(90);
 //LIMB 4 SEG 3
liftTest12.write(90);

 //LIMB 5 SEG 1
liftTest13.write(90);
 //LIMB 5 SEG 2
 liftTest14.write(90);
//LIMB 5 SEG 3
 liftTest15.write(90);

 //LIMB 6 SEG 1
liftTest16.write(90);
//LIMB 6 SEG 2
 liftTest17.write(90);
//LIMB 6 SEG 3
liftTest18.write(90);
 }


