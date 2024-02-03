
#include <Arduino.h>
#include <Servo.h>



// Define the mouth servo
Servo mouth;

// Initialize the mouth servo
void initMouth() {

  mouth.attach(46);
}

// Open and close the mouth
void mouthFunction() {
  mouth.write(130);
  delay(200);
  mouth.write(70);
  delay(200);
  mouth.write(130);
  delay(200);
  mouth.write(70);
  delay(200);
  mouth.write(70);
  delay(200);
  mouth.write(130);
  delay(200);
  mouth.write(70);
}

void test90(){
delay(200);
mouth.write(90);
delay(200);
}

void test0(){
delay(200);
mouth.write(0);
delay(200);
}

