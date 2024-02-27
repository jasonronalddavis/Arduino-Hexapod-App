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
test1.attach(15);
test2.attach(2);
test3.attach(21);
test4.attach(4);
test5.attach(16);
test6.attach(17);
test7.attach(5);
test8.attach(18);
test9.attach(19);

test10.attach(13);
test11.attach(12);
test12.attach(14);
test13.attach(27);
test14.attach(26);
test15.attach(25);
test16.attach(33);
test17.attach(32);
test18.attach(35);
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