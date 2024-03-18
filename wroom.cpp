#include <Arduino.h>
// #include <Wire.h>
#include <ESP32Servo.h>
// #include <Adafruit_PWMServoDriver.h>

#define SERVO_COUNT_ESP32 18 // Number of servos attached to ESP32

Servo servos_ESP32[SERVO_COUNT_ESP32]; // Array to hold ESP32 servo objects


void attachAndSetAngle(Servo &servo, int pin, int angle) {
  servo.attach(pin); // Attach servo to pin
  servo.write(angle); // Set initial angle
}


void testStretch() {
  // Move all ESP32 servos to 90 degrees
  for (int i = 0; i < SERVO_COUNT_ESP32; i++) {
    attachAndSetAngle(servos_ESP32[i], i, 90);
  }
}


void testLift() {
  // LIMB 1 SEG 1 (Hip)
  attachAndSetAngle(servos_ESP32[0], 19, 90);

  // LIMB 1 SEG 2 (Knee)
  attachAndSetAngle(servos_ESP32[1], 20, 135);

  // LIMB 1 SEG 3 (Ankle)
  attachAndSetAngle(servos_ESP32[2], 21, 125);



  // LIMB 2 SEG 1 (Hip)
  attachAndSetAngle(servos_ESP32[3], 47, 90);

  // LIMB 2 SEG 2 (Knee)
  attachAndSetAngle(servos_ESP32[4], 48, 135);

  // LIMB 2 SEG 3 (Ankle)
  attachAndSetAngle(servos_ESP32[5], 45, 125);




  // LIMB 3 SEG 1 (Hip)
  attachAndSetAngle(servos_ESP32[6], 41, 90);

  // LIMB 3 SEG 2 (Knee)
  attachAndSetAngle(servos_ESP32[7], 42, 135);

  // LIMB 3 SEG 3 (Ankle)
  attachAndSetAngle(servos_ESP32[8], 2, 125);



  // LIMB 4 SEG 1 (Hip)
  attachAndSetAngle(servos_ESP32[9], 4, 90);

  // LIMB 4 SEG 2 (Knee)
  attachAndSetAngle(servos_ESP32[10], 5, 135);

  // LIMB 4 SEG 3 (Ankle)
  attachAndSetAngle(servos_ESP32[11], 6, 125);



  // LIMB 5 SEG 1 (Hip)
  attachAndSetAngle(servos_ESP32[12], 16, 90);

  // LIMB 5 SEG 2 (Knee)
  attachAndSetAngle(servos_ESP32[13], 17, 135);

  // LIMB 5 SEG 3 (Ankle)
  attachAndSetAngle(servos_ESP32[14], 18, 125);



  // LIMB 5 SEG 1 (Hip)
  attachAndSetAngle(servos_ESP32[15], 12, 90);

  // LIMB 5 SEG 2 (Knee)
  attachAndSetAngle(servos_ESP32[16], 13, 135);

  // LIMB 5 SEG 3 (Ankle)
  attachAndSetAngle(servos_ESP32[17], 14, 125);

}




// void testCrawlOne() {
//   // LIMB 1 SEG 1
//   test1.write(90);
//   // LIMB 1 SEG 2
//   test2.write(130);
//   // LIMB 1 SEG 3
//   test3.write(135);

//   // LIMB 2 SEG 1
//   test4.write(90);
//   // LIMB 2 SEG 2
//   test5.write(60);
//   // LIMB 2 SEG 3
//   test6.write(125);

//   // LIMB 3 SEG 1
//   test7.write(90);
//   // LIMB 3 SEG 2
//   test8.write(120);
//   // LIMB 3 SEG 3
//   test9.write(120);

//   // LIMB 4 SEG 1
//   test10.write(90);
//   // LIMB 4 SEG 2
//   test11.write(60);
//   // LIMB 4 SEG 3
//   test12.write(130);

//   // LIMB 5 SEG 1
//   test13.write(90);
//   // LIMB 5 SEG 2
//   test14.write(120);
//   // LIMB 5 SEG 3
//   test15.write(120);

//   // LIMB 6 SEG 1
//   test16.write(90);
//   // LIMB 6 SEG 2
//   test17.write(60);
//   // LIMB 6 SEG 3
//   test18.write(120);
// }




// void testCrawlTwo(){
// //LIMB 1 SEG 1
// test1.write(65);
// //LIMB 1 SEG 2
// test2.write(60);
// //LIMB 1 SEG 3
// test3.write(120);

// //LIMB 2 SEG 1
// test4.write(115);
// //LIMB 2 SEG 2
// test5.write(65);
// //LIMB 2 SEG 3
// test6.write(130);

// //LIMB 3 SEG 1
// test7.write(70);
// //LIMB 3 SEG 2
// test8.write(60);
// //LIMB 3 SEG 3
// test9.write(135);

// //LIMB 4 SEG 1
// test10.write(90);
// //LIMB 4 SEG 2
// test11.write(65);
// //LIMB 4 SEG 3
// test12.write(125);

// //LIMB 5 SEG 1
// test13.write(110);
// //LIMB 5 SEG 2
// test14.write(110);
// //LIMB 5 SEG 3
// test15.write(130);

// //LIMB 6 SEG 1
// test16.write(80);
// //LIMB 6 SEG 2
// test17.write(60);
// //LIMB 6 SEG 3
// test18.write(130);
// }

// void testCrawlThree(){
// //LIMB 1 SEG 1
// test1.write(90);
// //LIMB 1 SEG 2
// test2.write(60);
// //LIMB 1 SEG 3
// test3.write(125);

// //LIMB 2 SEG 1
// test4.write(90);
// //LIMB 2 SEG 2
// test5.write(120);
// //LIMB 2 SEG 3
// test6.write(125);

// //LIMB 3 SEG 1
// test7.write(90);
// //LIMB 3 SEG 2
// test8.write(60);
// //LIMB 3 SEG 3
// test9.write(130);

// //LIMB 4 SEG 1
// test10.write(90);
// //LIMB 4 SEG 2
// test11.write(120);
// //LIMB 4 SEG 3
// test12.write(120);

// //LIMB 5 SEG 1
// test13.write(90);
// //LIMB 5 SEG 2
// test14.write(65);
// //LIMB 5 SEG 3
// test15.write(130);

// //LIMB 6 SEG 1
// test16.write(90);
// //LIMB 6 SEG 2
// test17.write(130);
// //LIMB 6 SEG 3
// test18.write(130);
// }

// void testCrawlFour(){
// //LIMB 1 SEG 1
// test1.write(105);
// //LIMB 1 SEG 2
// test2.write(60);
// //LIMB 1 SEG 3
// test3.write(135);

// //LIMB 2 SEG 1
// test4.write(80);
// //LIMB 2 SEG 2
// test5.write(65);
// //LIMB 2 SEG 3
// test6.write(120);

// //LIMB 3 SEG 1
// test7.write(100);
// //LIMB 3 SEG 2
// test8.write(65);
// //LIMB 3 SEG 3
// test9.write(115);

// //LIMB 4 SEG 1
// test10.write(95);
// //LIMB 4 SEG 2
// test11.write(65);
// //LIMB 4 SEG 3
// test12.write(130);

// //LIMB 5 SEG 1
// test13.write(70);
// //LIMB 5 SEG 2
// test14.write(70);
// //LIMB 5 SEG 3
// test15.write(125);

// //LIMB 6 SEG 1
// test16.write(100);
// //LIMB 6 SEG 2
// test17.write(60);
// //LIMB 6 SEG 3
// test18.write(120);

// }


// void testCrawlForward() {
// testCrawlOne();
// testCrawlTwo();
// testCrawlThree();
// testCrawlFour();
// }