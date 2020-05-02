/* Code from:
 *  EricklsOnline
 *  How To Mechatronics
 *  Modified by: Watis
 *  Date: 13 April 2020
 */
#include <Wire.h>
#include <VL53L0X.h>
#include <NewPing.h>

#define TRIGGER_PIN  4
#define ECHO_PIN     5
#define MAX_DISTANCE 1000

VL53L0X sensor1;
VL53L0X sensor2;
VL53L0X sensor3;
VL53L0X sensor4;
VL53L0X sensor5;
VL53L0X sensor6;
NewPing DistanceSensor(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// Motor A
//#define en1 A4
#define in1 A0
#define in2 A1

// Motor B
//#define en2 A5
#define in3 A2
#define in4 A3

// Motor C
//#define en3 A4
#define in5 6
#define in6 13

// Motor D
//#define en4 A5
#define in7 2
#define in8 3

int motorAspeed = 0;
int motorBspeed = 0;
int motorCspeed = 0;
int motorDspeed = 0;

void setup()
{
  // Sensor Readings
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  
//  delay(300);
  Wire.begin();
  Serial.begin(9600);
  //SENSOR
  pinMode(9, INPUT);
  delay(15);
  Serial.println("00");
  sensor1.init(true);
  Serial.println("01");
  delay(10);
  sensor1.setAddress((uint8_t)22);
  Serial.println("02");

  //SENSOR 2
  pinMode(10, INPUT);
  delay(15);
  sensor2.init(true);
  Serial.println("03");
  delay(10);
  sensor2.setAddress((uint8_t)23);
  Serial.println("04");

  //SENSOR 3
  pinMode(11, INPUT);
  delay(15);
  sensor3.init(true);
  Serial.println("05");
  delay(10);
  sensor3.setAddress((uint8_t)24);
  Serial.println("06");

  //SENSOR 4
  pinMode(12, INPUT);
  delay(15);
  sensor4.init(true);
  Serial.println("07");
  delay(10);
  sensor4.setAddress((uint8_t)25);
  Serial.println("08");
  
 //SENSOR 
  pinMode(7, INPUT);
  delay(15);
  sensor5.init(true);
  Serial.println("09");
  delay(10);
  sensor5.setAddress((uint8_t)26);
  Serial.println("10");

 //SENSOR6 
  pinMode(8, INPUT);
  delay(15);
  sensor6.init(true);
  Serial.println("11");
  delay(10);
  sensor6.setAddress((uint8_t)27);
  Serial.println("12");
  
  sensor1.setTimeout(250);
  sensor2.setTimeout(250);
  sensor3.setTimeout(250);
  sensor4.setTimeout(250);
  sensor5.setTimeout(250);
  sensor6.setTimeout(250);

//  Can't do this.  Did not hook up enable pins because there is no pin available
//  pinMode(en1, OUTPUT);   
//  pinMode(en2, OUTPUT);
 // pinMode(en3, OUTPUT);
//  pinMode(en4, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);

}

void forward(){
  Serial.print("Going forward...\t");
  // set Motor A backward RIGHT REAR WHEEL
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // set Motor B backward LEFT REAR WHEEL
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  // set Motor C backward LEFT FRONT WHEEL
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
 //set Motor D backward RIGHT FRONT WHEEL
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);    
}
void reverse(){
  Serial.print("Reversing...\t");
  // set Motor A backward RIGHT REAR WHEEL
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set Motor B backward LEFT REAR WHEEL
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set Motor C backward LEFT FRONT WHEEL
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
 //set Motor D backward RIGHT FRONT WHEEL
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
}
void pivot_R(){
  Serial.print("Pivot right...\t");
  // set Motor A - RIGHT REAR WHEEL
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // set Motor B - LEFT REAR WHEEL
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set Motor C - LEFT FRONT WHEEL
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  // set Motor D - RIGHT FRONT WHEEL
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);   
  delay(250);
}
void pivot_L(){
  Serial.print("Pivot Left...\t");
  // set Motor A - RIGHT REAR WHEEL
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set Motor B - LEFT REAR WHEEL
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  // set Motor C - LEFT FRONT WHEEL
  digitalWrite(in5, HIGH);
  digitalWrite(in6, HIGH);
  // set Motor D - RIGHT FRONT WHEEL
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);   
  delay(250);
}
void forward_R(){
  Serial.print("forward right...\t"); 
  // set Motor A - RIGHT REAR WHEEL
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // set Motor B - LEFT REAR WHEEL
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  // set Motor C - LEFT FRONT WHEEL
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  // set Motor D - RIGHT FRONT WHEEL
  digitalWrite(in7, HIGH);
  digitalWrite(in8, HIGH);
}
void forward_L(){
  Serial.print("forward left...\t"); 
  // set Motor A - RIGHT REAR WHEEL
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // set Motor B backward LEFT REAR WHEEL
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  // set Motor C backward LEFT FRONT WHEEL
  digitalWrite(in5, HIGH);
  digitalWrite(in6, HIGH);
  // set Motor D backward RIGHT FRONT WHEEL
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW); 

}
void aft_right(){
  Serial.print("Aft right...\t"); 
  // set Motor A - RIGHT REAR WHEEL 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  // set Motor B backward LEFT REAR WHEEL
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set Motor C backward LEFT FRONT WHEEL
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  // set Motor D backward RIGHT FRONT WHEEL
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
}
void aft_left(){
  Serial.print("Aft left...\t"); 
  // set Motor A - RIGHT REAR WHEEL 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // set Motor B backward LEFT REAR WHEEL
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  // set Motor C backward LEFT FRONT WHEEL
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  // set Motor D backward RIGHT FRONT WHEEL
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH); 
}
void back_up(){
  Serial.print("Backing up..\t"); 
  // set Motor A backward RIGHT REAR WHEEL
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set Motor B backward LEFT REAR WHEEL
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set Motor C backward LEFT FRONT WHEEL
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  // set Motor D backward RIGHT FRONT WHEEL
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);   
}
void halt(){

  Serial.print("HALT!...\t");
  // set Motor A - RIGHT REAR WHEEL
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  // set Motor B - LEFT REAR WHEEL
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  // set Motor C - LEFT FRONT WHEEL
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
  // set Motor D - RIGHT FRONT WHEEL
  digitalWrite(in7, LOW);
  digitalWrite(in8, LOW);   

}
void loop()
{

  int yAxis = 0;  // FOR HUMAN INTERFACE SUCH AS JOYCE STICK
    //CHECK DISTANCES - number ratio: 500 == 10cm
  long FF = (sensor6.readRangeSingleMillimeters());   // 5
  long LF = (sensor1.readRangeSingleMillimeters());  // 2
  long RF = (sensor5.readRangeSingleMillimeters());  // 6
  long BB = (sensor3.readRangeSingleMillimeters());   // 4
  long LB = (sensor2.readRangeSingleMillimeters());  // 3
  long RB = (sensor4.readRangeSingleMillimeters());  // 1
  unsigned int GN = DistanceSensor.ping_cm();

  if(GN > 300 || FF < 500 && LB > 500 && LF > 500 && RF > 500 && RB > 500){ 
// if there is de-elevation more than 5 cm, reverse
    reverse();
  }
  if(GN < 300 && FF > 500 && LB > 500 && LF > 500 && RF > 500 && RB > 500){  
// if Front sensor measures more than 500 ~ 10 cm     
    forward();
  }
  if(GN < 300 && FF > 500 && LB > 500 && LF > 500 && RF < 500 || RB < 500){ 
// If getting closer to the right, stop the right front wheel to correct direction to the left
    forward_L();
  }
  if(GN < 300 && FF > 500 && RF > 500 && RB > 500 && LF < 500 || LB < 500 ){
// If getting closer to the left, stop the left front wheel to correct direction to the 
    forward_R();
  }
  if(GN < 300 && FF < 500 && BB > 500 && LF > 500 && RF > 500){    
// if front is < 10 cm, steer right
      aft_right();
  }    

  if(GN < 300 && FF < 500 && BB > 500 && RF < 500 && LF > 500){ 
// if front is < 10 cm, steer right
      aft_left();
    }
  if(GN < 300 && FF < 500 && BB > 500 && RF < 500 && LF < 500){ 
// if front is < 10 cm, right front and left front are < 500
    back_up();
  }
  if(GN < 300 && FF < 500 && BB < 500 && RF > 500 && RB > 500){
// if can't go forward, can't go back, but right side is > 500
// PIVOT RIGHT
    pivot_R();
  }
  if(GN < 300 && FF < 500 && BB < 500 && RF < 500 && RB < 500 && LB > 500 && RB > 500){
// if can't go forward, can't go back, and right side is < 500, but left side is clear
// PIVOT LEFT
    pivot_L();
  } 
  if((GN < 300 && FF < 500 && BB < 500 && RF < 500 && RB < 500 && LB < 500 && RB < 500) 
  || (GN < 300 && FF < 500 && BB < 500 && RF > 500 && RB < 500 && LB < 500 && RB < 500)
  || (GN < 300 && FF < 500 && BB < 500 && RF < 500 && RB > 500 && LB < 500 && RB < 500)
  || (GN < 300 && FF < 500 && BB < 500 && RF < 500 && RB < 500 && LB > 500 && RB < 500)
  || (GN < 300 && FF < 500 && BB < 500 && RF < 500 && RB < 500 && LB < 500 && RB > 500)
  || (GN < 300 && FF < 500 && BB < 500 && RF > 500 && RB < 500 && LB > 500 && RB < 500)
  || (GN < 300 && FF < 500 && BB < 500 && RF < 500 && RB > 500 && LB < 500 && RB > 500)){
// if can't go forward, can't go back, and right side is < 500, but left side is clear
// PIVOT LEFT
    halt();
    Serial.print("Sending message, \"HELLLLP!!!\"\n");
  }   

  Serial.print("GN");
  Serial.print(GN);
  Serial.print("\tFF");
  Serial.print(FF);
  Serial.print("\tLF");
  Serial.print(LF); Serial.print("\tRF"); Serial.print(RF);
  Serial.print("\tLB");
  Serial.print(LB); Serial.print("\tRB"); Serial.print(RB);
  Serial.print("\tBB");
  Serial.print(BB);
  Serial.print("\tyAxis ");
  Serial.print(yAxis);
  Serial.print("\n");

}
