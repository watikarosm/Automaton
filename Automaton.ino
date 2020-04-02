#include <AFMotor.h>
#include <NewPing.h>
#include <VL53L0X.h>
#include <Wire.h>

VL53L0X sensor;
VL53L0X sensor2;
VL53L0X sensor3;
VL53L0X sensor4;

#define TRIGGER_PIN  2
#define ECHO_PIN     3
#define MAX_DISTANCE 255
AF_DCMotor Motor1(1);
AF_DCMotor Motor2(3);

NewPing DistanceRF_sensor(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
// L298N - FRONT MOTORS -----------
  // Motor A
//int en1 = 9;
int in1 = 8;
int in2 = 7;
  // Motor B
//int en2 = 3;
int in4 = 4;
int in3 = 5;
// End FRONT MOTORS -----------

// L298N - REAR MOTORS -----------
  // Motor C
//int en1 = 9;
int in5 = A0;
int in6 = A1;
  // Motor D
//int en2 = 3;
int in7 = A2;
int in8 = A3;
// End REAR MOTORS -----------

int maxSpeed = 255;
int left = 1;
int right = -1;
void setup()
{
    Serial.begin(9600);
  // Front 2 motors -----------
  //pinMode(en1, OUTPUT);
  //pinMode(en2, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  // End Front 2 motors -----------
  
  // Rear 2 motors -----------
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);
  // End Rear 2 motors -----------
  
  pinMode(6, INPUT_PULLUP);
  digitalWrite(6, HIGH);
  
  // VL53L0X -----------
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  // End VL53L0X -----------
  
  Wire.begin();

//SENSOR
  pinMode(9, INPUT);
  //delay(150);
  Serial.println("00");
  sensor.init(true);
  Serial.println("01");
  //delay(100);
  sensor.setAddress((uint8_t)22);
  Serial.println("02");

  //SENSOR 2
  pinMode(10, INPUT);
  //delay(150);
  sensor2.init(true);
  Serial.println("03");
  //delay(100);
  sensor2.setAddress((uint8_t)23);
  Serial.println("04");

  //SENSOR 3
  pinMode(11, INPUT);
  //delay(150);
  sensor3.init(true);
  Serial.println("05");
  //delay(100);
  sensor3.setAddress((uint8_t)24);
  Serial.println("06");

  //SENSOR 4
  pinMode(12, INPUT);
  //delay(150);
  sensor4.init(true);
  Serial.println("07");
  //delay(100);
  sensor4.setAddress((uint8_t)25);
  Serial.println("08");

  sensor.setTimeout(500);
  sensor2.setTimeout(500);
  sensor3.setTimeout(500);
  sensor4.setTimeout(500);
}

void loop()
{
   // int distanceLidar = RF_sensor.readRangeContinuousMillimeters();
    unsigned int cm = DistanceRF_sensor.ping_cm();
    int currentLeftSpeed = maxSpeed;
    int currentRightSpeed = maxSpeed;
    Serial.print("  Distance: ");
    Serial.print(cm);
    Serial.println("cm");
//CHECK DISTANCES
  long DISTANCE_F = (sensor.readRangeSingleMillimeters());
  long DISTANCE_L = (sensor2.readRangeSingleMillimeters());
  long DISTANCE_R = (sensor3.readRangeSingleMillimeters());
  long DISTANCE_B = (sensor4.readRangeSingleMillimeters());

  //FWD OR SENSOR
  if (sensor.timeoutOccurred())
  {
    Serial.print("Distance F (READING): ");
    Serial.println(" TIMEOUT");

  }
  else
  {
    Serial.print("Distance F   (mm): ");
    Serial.println(DISTANCE_F);
  }

  //FLT OR SENSOR2
  if (sensor2.timeoutOccurred())
  {
    Serial.print("Distance L (READING): ");
    Serial.println(" TIMEOUT");
  }
  else
  {
    Serial.print("Distance L   (mm): ");
    Serial.println(DISTANCE_L);
  }
  
  //FRT OR SENSOR3
  if (sensor3.timeoutOccurred())
  {
    Serial.print("Distance R (READING): ");
    Serial.println(" TIMEOUT");
  }
  else
  {
    Serial.print("Distance R   (mm): ");
    Serial.println(DISTANCE_R);
  }
  
  //FRT OR SENSOR4
  if (sensor4.timeoutOccurred())
  {
    Serial.print("Distance R (READING): ");
    Serial.println(" TIMEOUT");
  }
  else
  {
    Serial.print("Distance B   (mm): ");
    Serial.println(DISTANCE_B);
  } 
  delay(1000);//can change to a lower time like 100
    Serial.println();
     // Turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // Turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // go forward
  if(cm > 125){
    currentLeftSpeed = maxSpeed;
    currentRightSpeed = maxSpeed;
 //   analogWrite(en1, currentLeftSpeed);
//    analogWrite(en2, currentRightSpeed);
  }

  // if distance measure less than 125 cm, reduce speed
  if(cm < 125){
    currentLeftSpeed = (cm);
    currentRightSpeed = (cm);
//    analogWrite(en1, currentLeftSpeed);
//    analogWrite(en2, currentRightSpeed);
  }

  if(cm < 30){
    currentLeftSpeed = 100;
    currentRightSpeed = 100;
//    analogWrite(en1, currentLeftSpeed);
//    analogWrite(en2, currentRightSpeed);
  }

  if(cm <= 5){
         // Turn on motor A
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  // Turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
    currentLeftSpeed = 0;
    currentRightSpeed = 0;
//    analogWrite(en1, currentLeftSpeed);
//    analogWrite(en2, currentRightSpeed);
    
  }

  if(cm < 15){   // if too close reverse){
  // Turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // Turn on motor B
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
    
  }
    Serial.print("  FL Speed = ");
    Serial.print(currentLeftSpeed);
    Serial.print("  FR Speed = ");
    Serial.print(currentRightSpeed);
}
