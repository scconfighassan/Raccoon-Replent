/*
Author: Hassan Mahdi
Date:
Description: Raccooon Repellent based on Sound Frequency. Using 5 ultrasonic sensors
*/
#include <Arduino.h>
//First Ultrasonic Sensor
int trigPin = 11;
int echoPin = 12;
//Second
int trigPin2 = 10;
int echoPin2 = 9;
//Third
int trigPin3 = 6; //green jumper
int echoPin3 = 7; //yellow jumper
//Fourth
int trigPin4 = 4; //orange
int echoPin4 = 5; //red
//Fifth
int trigPin5 = 3; // brown
int echoPin5 = 2;
//speakerInput
int speaker = 8;
/*
plugs in sensor-detected distances thus triggers the speakers with a SPECIFIC Frequency.
(Frequency subject to change)
*/
void frequencyDistance(long cm1,long cm2, long cm3, long cm4, long cm5, int speakerInput1)
{ /*
  if (cm2<20&&cm1>20&&cm3>20&&cm4>20&&cm5>20){
      tone(speakerInput1,(15000));

    }

  if (cm1<20&&cm2>20&&cm3>20&&cm4>20&&cm5>20){
    tone(speakerInput1,15000);

  }
  if (cm3<20&&cm2>20&&cm1>20&&cm4>20&&cm5>20){
    tone(speakerInput1,15000);

  }
  if (cm4<20&&cm2>20&&cm3>20&&cm1>20&&cm5>20){
    tone(speakerInput1,15000);

  }
  if (cm5<20&&cm2>20&&cm3>20&&cm1>20&&cm4>20){
    tone(speakerInput1,15000);

  }
  */
  if ((cm1>20)&&(cm2>20)&&(cm3>20)&&(cm4>20)&&(cm5>20)){

    noTone(speakerInput1);
  }

  else{
  tone(speakerInput1,10000);
  }
}
/*
Ultrasonic Sensor HC-SR04
The sensor will emit a Frequency of 40k Hz. If there is an object on its path it will bounce back or get reflected
back to the sensor. You can calculate the distance by considering speed of sound and travel time.
speed of sound 340 m/s
*/
int sensors(int trig, int echo){
  long distance = 0;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH); //bounce sound wave
  return distance = (duration/2) / 29.1; // distance in cm.
}
void setup() {
      //Serial Port begin
      Serial.begin (9600);
  //Define inputs and outputs
  //First
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //Second
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  //Third
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  //Fourth
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
  //Fifth
  pinMode(trigPin5, OUTPUT);
  pinMode(echoPin5, INPUT);
}
void loop()
  {
    long d1= sensors(trigPin,echoPin);
    long d2= sensors(trigPin2,echoPin2);
    long d3= sensors(trigPin3,echoPin3);
    long d4= sensors(trigPin4,echoPin4);
    long d5= sensors(trigPin5,echoPin5);
    frequencyDistance(d1,d2,d3,d4,d5,speaker);
  }
