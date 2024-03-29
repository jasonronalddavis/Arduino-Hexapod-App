#include <Arduino.h>
#include <Wire.h>
#include <ESP32Servo.h>
#include <Adafruit_PWMServoDriver.h>

#define SERVO_COUNT_ESP32 18 // Number of servos attached to ESP32

// Servo servos_ESP32[SERVO_COUNT_ESP32]; // Array to hold ESP32 servo objects
Adafruit_PWMServoDriver board1 = Adafruit_PWMServoDriver(0x40); // Initialize the PCA9685 object for board 1
Adafruit_PWMServoDriver board2 = Adafruit_PWMServoDriver(0x41); // Initialize the PCA9685 object for board 2

void initTest(){
 board1.begin(); // Begin communication with board 1
  board1.setPWMFreq(60); // Set PWM frequency to 60Hz


   board2.begin(); // Begin communication with board 1
  board2.setPWMFreq(60); // Set PWM frequency to 60Hz
}


int angleToPulse(int ang) {
  int SERVOMIN = 125; // Minimum pulse length count
  int SERVOMAX = 575; // Maximum pulse length count
  int pulse = map(ang, 0, 180, SERVOMIN, SERVOMAX); // Map angle to pulse width
  Serial.print("Angle: "); Serial.print(ang);
  Serial.print(" pulse: "); Serial.println(pulse);
  return pulse;
}

void testStretch(){
    for (int servoNum = 0; servoNum < 18; servoNum++) {
        board1.setPWM(servoNum + 1, 0, angleToPulse(90)); // Set servo to 90 degrees on board 1
        board2.setPWM(servoNum + 1, 0, angleToPulse(90)); // Set servo to 90 degrees on board 2
    }
}


void testLift() {
  // LIMB 1 SEG 1 (Hip)
  board1.setPWM(1, 0, angleToPulse(90));

  // LIMB 1 SEG 2 (Knee)
  board1.setPWM(2, 0, angleToPulse(150));

  // LIMB 1 SEG 3 (Ankle)
  board1.setPWM(3, 0, angleToPulse(125));


  // LIMB 2 SEG 1 (Hip)
  board1.setPWM(4, 0, angleToPulse(90));

  // LIMB 2 SEG 2 (Knee)
  board1.setPWM(5, 0, angleToPulse(150));

  // LIMB 2 SEG 3 (Ankle)
  board1.setPWM(6, 0, angleToPulse(125));


  // LIMB 3 SEG 1 (Hip)
  board1.setPWM(7, 0, angleToPulse(90));

  // LIMB 3 SEG 2 (Knee)
  board1.setPWM(8, 0, angleToPulse(150));

  // LIMB 3 SEG 3 (Ankle)
  board1.setPWM(9, 0, angleToPulse(125));


  // LIMB 4 SEG 1 (Hip)
  board2.setPWM(1, 0, angleToPulse(90));

  // LIMB 4 SEG 2 (Knee)
  board2.setPWM(2, 0, angleToPulse(150));

  // LIMB 4 SEG 3 (Ankle)
  board2.setPWM(3, 0, angleToPulse(125));


  // LIMB 5 SEG 1 (Hip)
  board2.setPWM(4, 0, angleToPulse(90));

  // LIMB 5 SEG 2 (Knee)
  board2.setPWM(5, 0, angleToPulse(150));

  // LIMB 5 SEG 3 (Ankle)
  board2.setPWM(6, 0, angleToPulse(125));


    // LIMB 5 SEG 1 (Hip)
  board2.setPWM(7, 0, angleToPulse(90));

  // LIMB 5 SEG 2 (Knee)
  board2.setPWM(8, 0, angleToPulse(150));

  // LIMB 5 SEG 3 (Ankle)
  board2.setPWM(9, 0, angleToPulse(125));
}



 void testStand() {
  // LIMB 1 SEG 1 (Hip)
  board1.setPWM(1, 0, angleToPulse(90));

  // LIMB 1 SEG 2 (Knee)
  board1.setPWM(2, 0, angleToPulse(60));

  // LIMB 1 SEG 3 (Ankle)
  board1.setPWM(3, 0, angleToPulse(150));



  // LIMB 2 SEG 1 (Hip)
  board1.setPWM(4, 0, angleToPulse(90));

  // LIMB 2 SEG 2 (Knee)
  board1.setPWM(5, 0, angleToPulse(60));

  // LIMB 2 SEG 3 (Ankle)
  board1.setPWM(6, 0, angleToPulse(150));




  // LIMB 3 SEG 1 (Hip)
  board1.setPWM(7, 0, angleToPulse(90));

  // LIMB 3 SEG 2 (Knee)
  board1.setPWM(8, 0, angleToPulse(60));

  // LIMB 3 SEG 3 (Ankle)
  board1.setPWM(9, 0, angleToPulse(150));



  // LIMB 4 SEG 1 (Hip)
  board2.setPWM(1, 0, angleToPulse(90));

  // LIMB 4 SEG 2 (Knee)
  board2.setPWM(2, 0, angleToPulse(60));

  // LIMB 4 SEG 3 (Ankle)
  board2.setPWM(3, 0, angleToPulse(150));



  // LIMB 5 SEG 1 (Hip)
  board2.setPWM(4, 0, angleToPulse(90));

  // LIMB 5 SEG 2 (Knee)
  board2.setPWM(5, 0, angleToPulse(60));

  // LIMB 5 SEG 3 (Ankle)
  board2.setPWM(6, 0, angleToPulse(150));



    // LIMB 5 SEG 1 (Hip)
  board2.setPWM(7, 0, angleToPulse(90));

  // LIMB 5 SEG 2 (Knee)
  board2.setPWM(8, 0, angleToPulse(60));

  // LIMB 5 SEG 3 (Ankle)
  board2.setPWM(9, 0, angleToPulse(150));
}




// void testCrawlOne() {
//   // LIMB 1 SEG 1
//    board1.setPWM(1, 0, angleToPulse(90));
//   // LIMB 1 SEG 2
//   board1.setPWM(2, 0, angleToPulse(130));
//   // LIMB 1 SEG 3
//   board1.setPWM(3, 0, angleToPulse(135));

//   // LIMB 2 SEG 1
//    board1.setPWM(4, 0, angleToPulse(90));
//   // LIMB 2 SEG 2
//    board1.setPWM(5, 0, angleToPulse(60));
//   // LIMB 2 SEG 3
//    board1.setPWM(6, 0, angleToPulse(125));

//   // LIMB 3 SEG 1
//    board1.setPWM(7, 0, angleToPulse(90));
//   // LIMB 3 SEG 2
//    board1.setPWM(8, 0, angleToPulse(120));
//   // LIMB 3 SEG 3
//    board1.setPWM(9, 0, angleToPulse(120));

//   // LIMB 4 SEG 1
//    board2.setPWM(1, 0, angleToPulse(90));
//   // LIMB 4 SEG 2
//    board2.setPWM(2, 0, angleToPulse(60));
//   // LIMB 4 SEG 3
//    board2.setPWM(3, 0, angleToPulse(130));

//   // LIMB 5 SEG 1
//    board2.setPWM(4, 0, angleToPulse(90));
//   // LIMB 5 SEG 2
//    board2.setPWM(5, 0, angleToPulse(120));
//   // LIMB 5 SEG 3
//    board2.setPWM(6, 0, angleToPulse(120));

//   // LIMB 6 SEG 1
//    board2.setPWM(7, 0, angleToPulse(90));
//   // LIMB 6 SEG 2
//    board2.setPWM(8, 0, angleToPulse(60));
//   // LIMB 6 SEG 3
//    board2.setPWM(9, 0, angleToPulse(120));
// }




// void testCrawlTwo(){
// //LIMB 1 SEG 1
// board1.setPWM(1, 0, angleToPulse(65));
// //LIMB 1 SEG 2
// board1.setPWM(2, 0, angleToPulse(60));
// //LIMB 1 SEG 3
// board1.setPWM(3, 0, angleToPulse(120));

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