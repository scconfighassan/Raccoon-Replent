#include <Arduino.h>
//First Ultrasonic Sensor
int trigPin = 11;
int echoPin = 12;
//Second
int trigPin2 = 10;
int echoPin2 = 9;
int speaker = 8;

void frequencyDistance(long cm1,long cm2, int speakerInput)
{
  if (cm2<20&&cm1>20){
      tone(speakerInput,(100+cm2)*100);
    }

  if (cm1<20&&cm2>20){
    tone(speakerInput,(100+cm1)*100);
  }

  if ((cm1>20)&&(cm2>20)){

    noTone(speakerInput);
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
}
void loop()
  {
    long d1= sensors(trigPin2,echoPin2);
    long d2= sensors(trigPin,echoPin);
    frequencyDistance(d1,d2,speaker);
  }
