#include "I2Cdev.h"
#include <Wire.h>
#include <MPU6050.h>
MPU6050 accelgyro;
#define myBT Serial3     // 定義名稱 Serial  為 myBT

/*HC-SR04 and LedPin*/
int trigPin = 9;                  //Trig Pin
int echoPin = 8;                  //Echo Pin
long duration, distance;

int echoRed = 12;                   
int echoGreen = 11;
int echoBlue = 10;

/*MPU6050 X, Y values and LedPin*/
int16_t ax, ay, az;
int16_t gx, gy, gz;
int x=0,y=0;

int xLed = 2;//B
int yLed = 3;//G
int duoLed = 4;//R

/*timer*/
unsigned long timer = 0;

void setup() {
  myBT.begin(9600);
  Serial.begin(9600);
  
  /*HC-SR04*/
  pinMode(trigPin, OUTPUT);        //Define inputs and outputs 
  pinMode(echoPin, INPUT);
  pinMode(echoRed, OUTPUT);
  pinMode(echoGreen, OUTPUT);
  pinMode(echoBlue, OUTPUT);
  
  /*MPU6050_LED*/
  pinMode(xLed,OUTPUT);
  pinMode(yLed,OUTPUT);
  pinMode(duoLed,OUTPUT);
  
  // Initialize MPU6050
  Wire.begin();
  delay(500);
  accelgyro.initialize(); 
}

void loop() {
  HC_SR04();
  mpu6050();
  while (millis() - timer >=200){
    sendAPP();
    sendSerialCom();  
    timer = millis();
  }
}

void HC_SR04(){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);     // 給 Trig 高電位，持續 10微秒
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
   
    duration = pulseIn(echoPin, HIGH);   // 收到高電位時的時間
    distance = (duration/2) / 29.1;         // 將時間換算成距離 cm 或 inch  
     
    if (distance<=5){
      digitalWrite(echoRed,HIGH);
      digitalWrite(echoGreen,LOW);
      digitalWrite(echoBlue,LOW);
    }
    else if (distance<=10){
      digitalWrite(echoRed,LOW);
      digitalWrite(echoGreen,HIGH);
      digitalWrite(echoBlue,LOW);
    }
    else if (distance<=20){
      digitalWrite(echoRed,LOW);
      digitalWrite(echoGreen,LOW);
      digitalWrite(echoBlue,HIGH);
    } 
    else{
      digitalWrite(echoRed,LOW);
      digitalWrite(echoGreen,LOW);
      digitalWrite(echoBlue,LOW);  
    }
  }

void mpu6050(){
   accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

   x = map(ax,17000,-17000,-180,180);
   y = map(ay,17000,-17000,-180,180);

   if (abs(x)>=15 && abs(y)>=15){
    digitalWrite(duoLed,HIGH); 
    digitalWrite(xLed,LOW);
    digitalWrite(yLed,LOW);
   }
   else if (abs(x)>=15){
    digitalWrite(duoLed,LOW);
    digitalWrite(xLed,HIGH);
    digitalWrite(yLed,LOW);
   }
   else if (abs(y)>=15){
    digitalWrite(duoLed,LOW);
    digitalWrite(xLed,LOW);
    digitalWrite(yLed,HIGH);
   }
   else{
    digitalWrite(duoLed,LOW);
    digitalWrite(xLed,LOW);
    digitalWrite(yLed,LOW);    
    }
}
  
void sendAPP() {   // 傳送資料至APP ==> 用來顯示感測器資料
  String textAPP= "";
  textAPP = String(distance)+"&";
  textAPP = textAPP+String(x)+"&";
  textAPP = textAPP+String(-x)+"&";
  textAPP = textAPP+String(y)+"&";
  textAPP = textAPP+String(-y)+"&";
  myBT.println(textAPP);
}

void sendSerialCom(){
  Serial.println(String("*** 超音波距離: ") +distance + "CM") ;
  Serial.println(String("*** 水平傾斜角度:  ") +x + "度" + "\t ****垂直傾斜角度: " + y + "度") ;
  Serial.println("===================================================");
  
}
