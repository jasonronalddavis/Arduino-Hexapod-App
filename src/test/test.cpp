#include <Arduino.h>
#include <Wire.h>
#include <ESP32Servo.h>

//15, 20, 4, 16, 17., 5, 18, 19, 21, 22, 23, 
//34, 35, 32, 33, 25, 26, 27, 14, 12, 13, 

Servo test1;
Servo test2;
Servo test3;
Servo test4;
Servo test5;
Servo test6;
Servo test7;
Servo test8;
Servo test9;
Servo test10;
Servo test11;
Servo test12;
Servo test13;
Servo test14;
Servo test15;
Servo test16;
Servo test17;
Servo test18;

// Define the test2 servo
void initTest() {
test1.attach(14);
test2.attach(13);
test3.attach(12);
test4.attach(11);
test5.attach(10);
test6.attach(9);
test7.attach(46);
test8.attach(3);
test9.attach(8);

test10.attach(19);
test11.attach(20);
test12.attach(21);
test13.attach(47);
test14.attach(48);
test15.attach(45);
test16.attach(35);
test17.attach(36);
test18.attach(37);
}

 void testStretch(){
//LIMB 1 SEG 1
 test1.write(90);
 //LIMB 1 SEG 2
test2.write(90);
//LIMB 1 SEG 3
 test3.write(90);

 //LIMB 2 SEG 1
 test4.write(90);
 //LIMB 2 SEG 2
 test5.write(90);
///LIMB 2 SEG 3
 test6.write(90);

 //LIMB 3 SEG 1
test7.write(90);
//LIMB 3 SEG 2
 test8.write(90);
 //LIMB 3 SEG 3
 test9.write(90);

//LIMB 4 SEG 1
test10.write(90);
 //LIMB 4 SEG 2
 test11.write(90);
 //LIMB 4 SEG 3
test12.write(90);

 //LIMB 5 SEG 1
test13.write(90);
 //LIMB 5 SEG 2
 test14.write(90);
//LIMB 5 SEG 3
 test15.write(90);

 //LIMB 6 SEG 1
test16.write(90);
//LIMB 6 SEG 2
 test17.write(90);
//LIMB 6 SEG 3
test18.write(90);
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