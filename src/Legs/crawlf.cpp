#include <Arduino.h>
#include <Servo.h>

// Define the leg servos
Servo myServo2;
Servo myServo3;
Servo myServo4;
Servo myServo5;
Servo myServo6;
Servo myServo7;
Servo myServo8;
Servo myServo9;
Servo myServo10;
Servo myServo11;
Servo myServo12;
Servo myServo13;
Servo myServo14;
Servo myServo15;
Servo myServo16;
Servo myServo17;
Servo myServo18;
Servo myServo19;

// Initialize the leg servos
void initLegs() {
  myServo2.attach(2);
  myServo3.attach(3);
  myServo4.attach(4);
  myServo5.attach(5);
  myServo6.attach(6);
  myServo7.attach(7);
  myServo8.attach(8);
  myServo9.attach(9);
  myServo10.attach(10);
  myServo11.attach(11);
  myServo12.attach(12);
  myServo13.attach(13);
  myServo14.attach(14);
  myServo15.attach(15);
  myServo16.attach(16);
  myServo17.attach(17);
  myServo18.attach(18);
  myServo19.attach(19);
}

// Crawl sequence 1
void crawlOne() {
  // LIMB 1 SEG 1
  myServo2.write(90);
  // LIMB 1 SEG 2
  myServo3.write(130);
  // LIMB 1 SEG 3
  myServo4.write(135);

  // LIMB 2 SEG 1
  myServo5.write(90);
  // LIMB 2 SEG 2
  myServo6.write(60);
  // LIMB 2 SEG 3
  myServo7.write(125);

  // LIMB 3 SEG 1
  myServo8.write(90);
  // LIMB 3 SEG 2
  myServo9.write(120);
  // LIMB 3 SEG 3
  myServo10.write(120);

  // LIMB 4 SEG 1
  myServo11.write(90);
  // LIMB 4 SEG 2
  myServo12.write(60);
  // LIMB 4 SEG 3
  myServo13.write(130);

  // LIMB 5 SEG 1
  myServo14.write(90);
  // LIMB 5 SEG 2
  myServo15.write(120);
  // LIMB 5 SEG 3
  myServo16.write(120);

  // LIMB 6 SEG 1
  myServo17.write(90);
  // LIMB 6 SEG 2
  myServo18.write(60);
  // LIMB 6 SEG 3
  myServo19.write(120);
}




void crawlTwo(){
//LIMB 1 SEG 1
myServo2.write(65);
//LIMB 1 SEG 2
myServo3.write(60);
//LIMB 1 SEG 3
myServo4.write(120);

//LIMB 2 SEG 1
myServo5.write(115);
//LIMB 2 SEG 2
myServo6.write(65);
//LIMB 2 SEG 3
myServo7.write(130);

//LIMB 3 SEG 1
myServo8.write(70);
//LIMB 3 SEG 2
myServo9.write(60);
//LIMB 3 SEG 3
myServo10.write(135);

//LIMB 4 SEG 1
myServo11.write(90);
//LIMB 4 SEG 2
myServo12.write(65);
//LIMB 4 SEG 3
myServo13.write(125);

//LIMB 5 SEG 1
myServo14.write(110);
//LIMB 5 SEG 2
myServo15.write(110);
//LIMB 5 SEG 3
myServo16.write(130);

//LIMB 6 SEG 1
myServo17.write(80);
//LIMB 6 SEG 2
myServo18.write(60);
//LIMB 6 SEG 3
myServo19.write(130);
}

void crawlThree(){
//LIMB 1 SEG 1
myServo2.write(90);
//LIMB 1 SEG 2
myServo3.write(60);
//LIMB 1 SEG 3
myServo4.write(125);

//LIMB 2 SEG 1
myServo5.write(90);
//LIMB 2 SEG 2
myServo6.write(120);
//LIMB 2 SEG 3
myServo7.write(125);

//LIMB 3 SEG 1
myServo8.write(90);
//LIMB 3 SEG 2
myServo9.write(60);
//LIMB 3 SEG 3
myServo10.write(130);

//LIMB 4 SEG 1
myServo11.write(90);
//LIMB 4 SEG 2
myServo12.write(120);
//LIMB 4 SEG 3
myServo13.write(120);

//LIMB 5 SEG 1
myServo14.write(90);
//LIMB 5 SEG 2
myServo15.write(65);
//LIMB 5 SEG 3
myServo16.write(130);

//LIMB 6 SEG 1
myServo17.write(90);
//LIMB 6 SEG 2
myServo18.write(130);
//LIMB 6 SEG 3
myServo19.write(130);
}

void crawlFour(){
//LIMB 1 SEG 1
myServo2.write(105);
//LIMB 1 SEG 2
myServo3.write(60);
//LIMB 1 SEG 3
myServo4.write(135);

//LIMB 2 SEG 1
myServo5.write(80);
//LIMB 2 SEG 2
myServo6.write(65);
//LIMB 2 SEG 3
myServo7.write(120);

//LIMB 3 SEG 1
myServo8.write(100);
//LIMB 3 SEG 2
myServo9.write(65);
//LIMB 3 SEG 3
myServo10.write(115);

//LIMB 4 SEG 1
myServo11.write(95);
//LIMB 4 SEG 2
myServo12.write(65);
//LIMB 4 SEG 3
myServo13.write(130);

//LIMB 5 SEG 1
myServo14.write(70);
//LIMB 5 SEG 2
myServo15.write(70);
//LIMB 5 SEG 3
myServo16.write(125);

//LIMB 6 SEG 1
myServo17.write(100);
//LIMB 6 SEG 2
myServo18.write(60);
//LIMB 6 SEG 3
myServo19.write(120);

}


//LIFT ALL LEGS
void liftFunction(){
// LIMB 1 SEG 1
myServo2.write(90);
// //LIMB 1 SEG 2
 myServo3.write(135);
// //LIMB 1 SEG 3
 myServo4.write(125);

// //LIMB 2 SEG 1
myServo5.write(90);
// //LIMB 2 SEG 2
 myServo6.write(135);
// //LIMB 2 SEG 3
 myServo7.write(125);

// LIMB 3 SEG 1
 myServo8.write(90);
// //LIMB 3 SEG 2
 myServo9.write(135);
// //LIMB 3 SEG 3
 myServo10.write(125);

// //LIMB 4 SEG 1
 myServo11.write(90);
// //LIMB 4 SEG 2
 myServo12.write(135);
// //LIMB 4 SEG 3
 myServo13.write(125);

// //LIMB 5 SEG 1
 myServo14.write(90);
// //LIMB 5 SEG 2
 myServo15.write(135);
// //LIMB 5 SEG 3
 myServo16.write(125);

// //LIMB 6 SEG 1
 myServo17.write(90);
// //LIMB 6 SEG 2
 myServo18.write(135);
// //LIMB 6 SEG 3
myServo19.write(125);
 delay(200);
 }


 //STAND
 void standFunction(){
// //LIMB 1 SEG 1
 myServo2.write(90);
// //LIMB 1 SEG 2
 myServo3.write(65);
// //LIMB 1 SEG 3
myServo4.write(150);

// //LIMB 2 SEG 1
 myServo5.write(90);
// //LIMB 2 SEG 2
myServo6.write(65);
// //LIMB 2 SEG 3
 myServo7.write(150);

// //LIMB 3 SEG 1
 myServo8.write(90);
// //LIMB 3 SEG 2
 myServo9.write(65);
// //LIMB 3 SEG 3
 myServo10.write(150);

// //LIMB 4 SEG 1
 myServo11.write(90);
// //LIMB 4 SEG 2
 myServo12.write(65);
// //LIMB 4 SEG 3
 myServo13.write(150);

// //LIMB 5 SEG 1
 myServo14.write(90);
// //LIMB 5 SEG 2
 myServo15.write(65);
// //LIMB 5 SEG 3
 myServo16.write(150);

// //LIMB 6 SEG 1
 myServo17.write(90);
// //LIMB 6 SEG 2
 myServo18.write(65);
// //LIMB 6 SEG 3
 myServo19.write(150);
// delay(2000);
 }

// //FLEX LEGS
 void flexFunction(){
 myServo2.write(90);
 //LIMB 1 SEG 2
 myServo3.write(90);
// //LIMB 1 SEG 3
 myServo4.write(125);

 //LIMB 2 SEG 1
 myServo5.write(90);
//LIMB 2 SEG 2
 myServo6.write(90);
 //LIMB 2 SEG 3
 myServo7.write(125);

 //LIMB 3 SEG 1
 myServo8.write(90);
//LIMB 3 SEG 2
 myServo9.write(90);
//LIMB 3 SEG 3
 myServo10.write(125);

 //LIMB 4 SEG 1
 myServo11.write(90);
//LIMB 4 SEG 2
 myServo12.write(90);
 //LIMB 4 SEG 3
 myServo13.write(125);

 //LIMB 5 SEG 1
 myServo14.write(90);
 //LIMB 5 SEG 2
 myServo15.write(90);
 //LIMB 5 SEG 3
myServo16.write(125);

 //LIMB 6 SEG 1
myServo17.write(90);
 //LIMB 6 SEG 2
myServo18.write(90);
//LIMB 6 SEG 3
myServo19.write(125);
delay(2000);
 }



 void stretch(){
//LIMB 1 SEG 1
 myServo2.write(90);
 //LIMB 1 SEG 2
myServo3.write(90);
//LIMB 1 SEG 3
 myServo4.write(90);

 //LIMB 2 SEG 1
 myServo5.write(90);
 //LIMB 2 SEG 2
 myServo6.write(90);
///LIMB 2 SEG 3
 myServo7.write(90);

 //LIMB 3 SEG 1
myServo8.write(90);
//LIMB 3 SEG 2
 myServo9.write(90);
 //LIMB 3 SEG 3
 myServo10.write(90);

//LIMB 4 SEG 1
myServo11.write(90);
 //LIMB 4 SEG 2
 myServo12.write(90);
 //LIMB 4 SEG 3
myServo13.write(90);

 //LIMB 5 SEG 1
myServo14.write(90);
 //LIMB 5 SEG 2
 myServo15.write(90);
//LIMB 5 SEG 3
 myServo16.write(90);

 //LIMB 6 SEG 1
myServo17.write(90);
//LIMB 6 SEG 2
 myServo18.write(90);
//LIMB 6 SEG 3
myServo19.write(90);
 }


void crawlForward(){
 delay(180);
 crawlOne();
  delay(170);
crawlTwo();
 delay(180);
 crawlThree();
 delay(170);
 crawlFour();
}

  void defaultMove(){
stretch();
 delay(2000);
 liftFunction();
 delay(500);
 standFunction();
 delay(500);
 flexFunction();
 standFunction();
}