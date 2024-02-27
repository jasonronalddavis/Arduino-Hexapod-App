
// #include <SPI.h>
// #define SERVO_FREQ 50 // or whatever value you want
// #include <Arduino.h>
// #include <Adafruit_PWMServoDriver.h>
// #include <Wire.h>



// Adafruit_PWMServoDriver pwm3;


// void initLegs() {
// Wire.begin();
//   pwm3.begin(); // Corrected the variable name from pca to pwm3
//  pwm3.setOscillatorFrequency(27000000); // Set oscillator frequency
//   pwm3.setPWMFreq(SERVO_FREQ);  // Set PWM frequency for servos
// }

// void crawlOne() {
//     pwm3.setPWM(2, 0, 300);  // LIMB 1 SEG 1
//     pwm3.setPWM(3, 0, 500);  // LIMB 1 SEG 2
//     pwm3.setPWM(4, 0, 525);  // LIMB 1 SEG 3

//     pwm3.setPWM(5, 0, 300);  // LIMB 2 SEG 1
//     pwm3.setPWM(6, 0, 150);  // LIMB 2 SEG 2
//     pwm3.setPWM(7, 0, 500);  // LIMB 2 SEG 3

//     pwm3.setPWM(8, 0, 300);  // LIMB 3 SEG 1
//     pwm3.setPWM(9, 0, 450);  // LIMB 3 SEG 2
//     pwm3.setPWM(10, 0, 450); // LIMB 3 SEG 3

//     pwm3.setPWM(11, 0, 300); // LIMB 4 SEG 1
//     pwm3.setPWM(12, 0, 150); // LIMB 4 SEG 2
//     pwm3.setPWM(13, 0, 525); // LIMB 4 SEG 3

//     pwm3.setPWM(14, 0, 300); // LIMB 5 SEG 1
//     pwm3.setPWM(15, 0, 450); // LIMB 5 SEG 2
//     pwm3.setPWM(16, 0, 450); // LIMB 5 SEG 3

//     pwm3.setPWM(17, 0, 300); // LIMB 6 SEG 1
//     pwm3.setPWM(18, 0, 150); // LIMB 6 SEG 2
//     pwm3.setPWM(19, 0, 450); // LIMB 6 SEG 3
// }



// void crawlTwo() {
//     pwm3.setPWM(2, 0, 400);  // Example value for LIMB 1 SEG 1
//     pwm3.setPWM(3, 0, 300);  // Example value for LIMB 1 SEG 2
//     pwm3.setPWM(4, 0, 600);  // Example value for LIMB 1 SEG 3

//     pwm3.setPWM(5, 0, 400);  // Example value for LIMB 2 SEG 1
//     pwm3.setPWM(6, 0, 300);  // Example value for LIMB 2 SEG 2
//     pwm3.setPWM(7, 0, 600);  // Example value for LIMB 2 SEG 3

//     pwm3.setPWM(8, 0, 400);  // Example value for LIMB 3 SEG 1
//     pwm3.setPWM(9, 0, 300);  // Example value for LIMB 3 SEG 2
//     pwm3.setPWM(10, 0, 600); // Example value for LIMB 3 SEG 3

//     pwm3.setPWM(11, 0, 400); // Example value for LIMB 4 SEG 1
//     pwm3.setPWM(12, 0, 300); // Example value for LIMB 4 SEG 2
//     pwm3.setPWM(13, 0, 600); // Example value for LIMB 4 SEG 3

//     pwm3.setPWM(14, 0, 400); // Example value for LIMB 5 SEG 1
//     pwm3.setPWM(15, 0, 300); // Example value for LIMB 5 SEG 2
//     pwm3.setPWM(16, 0, 600); // Example value for LIMB 5 SEG 3

//     pwm3.setPWM(17, 0, 400); // Example value for LIMB 6 SEG 1
//     pwm3.setPWM(18, 0, 300); // Example value for LIMB 6 SEG 2
//     pwm3.setPWM(19, 0, 600); // Example value for LIMB 6 SEG 3
// }


// void crawlThree() {
//     pwm3.setPWM(2, 0, 500);  // Example value for LIMB 1 SEG 1
//     pwm3.setPWM(3, 0, 400);  // Example value for LIMB 1 SEG 2
//     pwm3.setPWM(4, 0, 550);  // Example value for LIMB 1 SEG 3

//     pwm3.setPWM(5, 0, 500);  // Example value for LIMB 2 SEG 1
//     pwm3.setPWM(6, 0, 400);  // Example value for LIMB 2 SEG 2
//     pwm3.setPWM(7, 0, 550);  // Example value for LIMB 2 SEG 3

//     pwm3.setPWM(8, 0, 500);  // Example value for LIMB 3 SEG 1
//     pwm3.setPWM(9, 0, 400);  // Example value for LIMB 3 SEG 2
//     pwm3.setPWM(10, 0, 550); // Example value for LIMB 3 SEG 3

//     pwm3.setPWM(11, 0, 500); // Example value for LIMB 4 SEG 1
//     pwm3.setPWM(12, 0, 400); // Example value for LIMB 4 SEG 2
//     pwm3.setPWM(13, 0, 550); // Example value for LIMB 4 SEG 3

//     pwm3.setPWM(14, 0, 500); // Example value for LIMB 5 SEG 1
//     pwm3.setPWM(15, 0, 400); // Example value for LIMB 5 SEG 2
//     pwm3.setPWM(16, 0, 550); // Example value for LIMB 5 SEG 3

//     pwm3.setPWM(17, 0, 500); // Example value for LIMB 6 SEG 1
//     pwm3.setPWM(18, 0, 400); // Example value for LIMB 6 SEG 2
//     pwm3.setPWM(19, 0, 550); // Example value for LIMB 6 SEG 3
// }

// void crawlFour() {
//     pwm3.setPWM(2, 0, 400);  // Example value for LIMB 1 SEG 1
//     pwm3.setPWM(3, 0, 500);  // Example value for LIMB 1 SEG 2
//     pwm3.setPWM(4, 0, 450);  // Example value for LIMB 1 SEG 3

//     pwm3.setPWM(5, 0, 400);  // Example value for LIMB 2 SEG 1
//     pwm3.setPWM(6, 0, 550);  // Example value for LIMB 2 SEG 2
//     pwm3.setPWM(7, 0, 450);  // Example value for LIMB 2 SEG 3

//     pwm3.setPWM(8, 0, 400);  // Example value for LIMB 3 SEG 1
//     pwm3.setPWM(9, 0, 500);  // Example value for LIMB 3 SEG 2
//     pwm3.setPWM(10, 0, 450); // Example value for LIMB 3 SEG 3

//     pwm3.setPWM(11, 0, 400); // Example value for LIMB 4 SEG 1
//     pwm3.setPWM(12, 0, 550); // Example value for LIMB 4 SEG 2
//     pwm3.setPWM(13, 0, 450); // Example value for LIMB 4 SEG 3

//     pwm3.setPWM(14, 0, 400); // Example value for LIMB 5 SEG 1
//     pwm3.setPWM(15, 0, 500); // Example value for LIMB 5 SEG 2
//     pwm3.setPWM(16, 0, 450); // Example value for LIMB 5 SEG 3

//     pwm3.setPWM(17, 0, 400); // Example value for LIMB 6 SEG 1
//     pwm3.setPWM(18, 0, 550); // Example value for LIMB 6 SEG 2
//     pwm3.setPWM(19, 0, 450); // Example value for LIMB 6 SEG 3
// }



// //LIFT ALL LEGS
// void liftFunction() {
//     // Set PWM values for all servos to lift the legs
//     pwm3.setPWM(2, 0, 300);  // Example value for LIMB 1 SEG 1
//     pwm3.setPWM(3, 0, 600);  // Example value for LIMB 1 SEG 2
//     pwm3.setPWM(4, 0, 600);  // Example value for LIMB 1 SEG 3

//     pwm3.setPWM(5, 0, 300);  // Example value for LIMB 2 SEG 1
//     pwm3.setPWM(6, 0, 600);  // Example value for LIMB 2 SEG 2
//     pwm3.setPWM(7, 0, 600);  // Example value for LIMB 2 SEG 3

//     // Repeat the process for the remaining servos
//     // ...

//     pwm3.setPWM(17, 0, 300); // Example value for LIMB 6 SEG 1
//     pwm3.setPWM(18, 0, 600); // Example value for LIMB 6 SEG 2
//     pwm3.setPWM(19, 0, 600); // Example value for LIMB 6 SEG 3
// }


//  //STAND
//  void standFunction() {
//     // Set PWM values for all servos to stand
//     pwm3.setPWM(2, 0, 300);  // Example value for LIMB 1 SEG 1
//     pwm3.setPWM(3, 0, 450);  // Example value for LIMB 1 SEG 2
//     pwm3.setPWM(4, 0, 600);  // Example value for LIMB 1 SEG 3

//     pwm3.setPWM(5, 0, 300);  // Example value for LIMB 2 SEG 1
//     pwm3.setPWM(6, 0, 450);  // Example value for LIMB 2 SEG 2
//     pwm3.setPWM(7, 0, 600);  // Example value for LIMB 2 SEG 3

//     // Repeat the process for the remaining servos
//     // ...

//     pwm3.setPWM(17, 0, 300); // Example value for LIMB 6 SEG 1
//     pwm3.setPWM(18, 0, 450); // Example value for LIMB 6 SEG 2
//     pwm3.setPWM(19, 0, 600); // Example value for LIMB 6 SEG 3
// }


// // //FLEX LEGS
//  void flexFunction() {
//     // Set PWM values for all servos to flex the legs
//     pwm3.setPWM(2, 0, 300);  // Example value for LIMB 1 SEG 1
//     pwm3.setPWM(3, 0, 350);  // Example value for LIMB 1 SEG 2
//     pwm3.setPWM(4, 0, 400);  // Example value for LIMB 1 SEG 3

//     pwm3.setPWM(5, 0, 300);  // Example value for LIMB 2 SEG 1
//     pwm3.setPWM(6, 0, 350);  // Example value for LIMB 2 SEG 2
//     pwm3.setPWM(7, 0, 400);  // Example value for LIMB 2 SEG 3

//     // Repeat the process for the remaining servos
//     // ...

//     pwm3.setPWM(17, 0, 300); // Example value for LIMB 6 SEG 1
//     pwm3.setPWM(18, 0, 350); // Example value for LIMB 6 SEG 2
//     pwm3.setPWM(19, 0, 400); // Example value for LIMB 6 SEG 3
// }

// void stretch() {
//     // Set PWM values for all servos to move them to 90 degrees
//     for (uint8_t servoPin = 2; servoPin <= 19; servoPin++) {
//         pwm3.setPWM(servoPin, 0, 307);  // 90 degrees position for all servos
//     }
// }

// void crawlForward(){
//  delay(180);
//  crawlOne();
//   delay(170);
// crawlTwo();
//  delay(180);
//  crawlThree();
//  delay(170);
//  crawlFour();
// }

//   void defaultMove(){

//  delay(2000);
//  liftFunction();
//  delay(500);
//  standFunction();
//  delay(500);
//  flexFunction();
//  standFunction();
// }







// #define SERVO_FREQ 50 // or whatever value you want
// #include <Arduino.h>
// #include <Wire.h>
// #include <Adafruit_PWMServoDriver.h>
// #include <SPI.h>



// Adafruit_PWMServoDriver pwm1;

// // Define the mouth servo
// void initMouth() {
//   Wire.begin();


//   pwm1.begin();

//    pwm1.setOscillatorFrequency(27000000); // Set oscillator frequency
//   pwm1.setPWMFreq(SERVO_FREQ);  // Set PWM frequency for servos
// }
// void mouthFunction() {
//   pwm1.setPWM(0, 0, 130);  // Open the mouth
//   delay(200);
//   pwm1.setPWM(0, 0, 70);   // Close the mouth
//   delay(200);
//   pwm1.setPWM(0, 0, 130);  // Open the mouth
//   delay(200);
//   pwm1.setPWM(0, 0, 70);   // Close the mouth
//   delay(200);
//   pwm1.setPWM(0, 0, 70);   // Close the mouth
//   delay(200);
//   pwm1.setPWM(0, 0, 130);  // Open the mouth
//   delay(200);
//   pwm1.setPWM(0, 0, 70);   // Close the mouth
// }

// void test90() {
//   delay(200);
//   pwm1.setPWM(2, 0, 90);   // Test position 90 degrees
//   delay(200);
// }

// void test0() {
//   delay(200);
//   pwm1.setPWM(2, 0, 0);    // Test position 0 degrees
//   delay(200);
// }


