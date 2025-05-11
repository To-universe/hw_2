#include <Arduino.h>

int pinnum[3] = {2,5,27};
String s = "";

void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<3;i++)
  {
    pinMode(pinnum[i],OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int EQUAL1=0,EQUAL2=0,EQUAL3=0,EQUAL4=0;

  if (Serial.available() > 0)
  {
    s=Serial.readString();
    EQUAL1 = s.equals("1");
    EQUAL2 = s.equals("2");
    EQUAL3 = s.equals("3");
    EQUAL4 = s.equals("e");
    if(EQUAL1 | EQUAL2 | EQUAL3){
      digitalWrite(pinnum[s.toInt()-1],HIGH);
    }else if(EQUAL4){
      for(int i= 0;i<3;i++){
        digitalWrite(pinnum[i],LOW);
      }
    }
  }
  
  if(EQUAL1){
    Serial.println("LED1 turn on");
  }else if(EQUAL2){
    Serial.println("LED2 turn on");
  }else if(EQUAL3){
    Serial.println("LED3 turn on");
  }else if(EQUAL4){
    Serial.println("all turn off");
  }
}

