/*
Author: Hassan Mahdi
Date:
Description: Raccooon Repellent based on Sound Frequency.
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
//speakerInput
int speaker = 8;
int speaker2= 2;
void frequencyDistance(long cm1,long cm2, long cm3, long cm4, int speakerInput1, int speakerInput2)
{
  if (cm2<20&&cm1>20&&cm3>20&&cm4>20){
      tone(speakerInput1,(10000));
      tone(speakerInput2,(10000));
    }

  if (cm1<20&&cm2>20&&cm3>20&&cm4>20){
    tone(speakerInput1,10000);
    tone(speakerInput2,10000);
  }
  if (cm3<20&&cm2>20&&cm1>20&&cm4>20){
    tone(speakerInput1,10000);
    tone(speakerInput2,10000);
  }
  if (cm4<20&&cm2>20&&cm3>20&&cm1>20){
    tone(speakerInput1,10000);
    tone(speakerInput2,10000);
  }
  if ((cm1>20)&&(cm2>20)&&(cm3>20)&&(cm4>20)){

    noTone(speakerInput1);
    noTone(speakerInput2);

  }

}
int sensors(int trig, int echo){
  long distance = 0;
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);
  return distance = (duration/2) / 29.1;
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
}
void loop()
  {
    long d1= sensors(trigPin,echoPin);
    long d2= sensors(trigPin2,echoPin2);
    long d3= sensors(trigPin3,echoPin3);
    long d4= sensors(trigPin4,echoPin4);
    frequencyDistance(d1,d2,d3,d4,speaker,speaker2);
  }
