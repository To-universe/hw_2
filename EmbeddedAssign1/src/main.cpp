#include <Arduino.h>

//定义存储引脚序号的数组
int  pinnum[6] = {15,2,4,5,27,25};
void setup() {
  for (int i = 0; i < 6; i++)
  {
    pinMode(pinnum[i],OUTPUT);  //将接口D15,D2,D4,D5,D27,D25设为输出
  }
  
}

void loop() {
  //正方向灯逐个亮起，每个亮0.5秒
  for (int i = 0; i < 6; i++)
  {
    digitalWrite(pinnum[i],HIGH);
    delay(500);
    digitalWrite(pinnum[i],LOW);
  }
  delay(500);
  //反方向进行一遍
  for (int i = 5; i >= 0; i--)
  {
    digitalWrite(pinnum[i],HIGH);
    delay(500);
    digitalWrite(pinnum[i],LOW);
  }
  delay(500);
}