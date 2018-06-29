#include <Arduino.h>
//First Ultrasonic Sensor
int trigPin = 11;
int echoPin = 12;
//Second
int trigPin2 = 10;
int echoPin2 = 9;
long duration, cm, firstSen, secondSen;
int speaker = 8;

void frequencyDistance(long cm, int speakerInput)
{

    tone(speakerInput,(100+cm)*100);
      if (cm>20){

      noTone(speakerInput);
    }
}
void sensors(int trig, int echo){
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  cm = (duration/2) / 29.1;

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
// hello dere no

void loop()
{

sensors(trigPin,echoPin);
firstSen=cm;
frequencyDistance(firstSen, speaker);
sensors(trigPin2,echoPin2);
secondSen= cm;
frequencyDistance(secondSen, speaker);
}
