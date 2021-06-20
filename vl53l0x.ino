#include <Wire.h>    // This Library is necessary for i2c communication
#include <VL53L0X.h> //We have include the library prepared for the Time of Flight sensor we use.
#include <Servo.h>   // Servo library is necessary for servo movement

VL53L0X sensor;
Servo servoMot;

#define HIGH_ACCURACY // - higher accuracy at the cost of lower speed

int a = 0;    //initialize for rotation of servo 0 to 180
int b = 180;  //initialize for rotation of servo 180 to 0

void setup()
{
  Serial.begin(115200); //Baudrate = 115200
  Wire.begin();         //For communication

  sensor.setTimeout(500);
  if (!sensor.init())
  {
    Serial.println("Failed to detect and initialize sensor!");
    while (1) {}
  }

#if defined HIGH_ACCURACY
  // increase timing budget to 200 ms
  sensor.setMeasurementTimingBudget(200000);
#endif

servoMot.attach(3); //Servo Motor pin is Digital PWM 3

}

void loop()
{
  for (a = 0; a <= 180; a += 1) { // Servo motor movement from 0 to 180 is provided. We set it to increase by 1 degree with each step.
                                  
    servoMot.write(a); // Servo motor position
    Serial.print(a); // Angle degree
    Serial.print(' ');
    Serial.print(sensor.readRangeSingleMillimeters()); // Distance value
    Serial.println();
  }
  for (b = 180; b >= 0; b-= 1) { // Servo motor movement from 180 to 0 is provided. We set it to decrease by 1 degree with each step.
                                 
    servoMot.write(b); // Servo motor position
    Serial.print(b);  // Angle degree
    Serial.print(' ');
    Serial.print(sensor.readRangeSingleMillimeters()); // Distance value
    Serial.println();
  }
}
