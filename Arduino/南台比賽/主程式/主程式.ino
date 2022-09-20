#include <SoftwareSerial.h>
#include <MPU6050.h>
SoftwareSerial BT(5,4); //TX先，RX後
MPU6050 xytest; //三軸加速計名稱 （SCL接SCL SDA接SDA）


//超音波 
int trig=7,echo=6;
//超音波LED燈 
int red=10,green=9,blue=8;
//三軸加速計LED
int xred=13,xgreen=12,xblue=11;
int16_t ax, ay, az,  gx, gy, gz;
//變數
int n,v,x=0,y=0;
//計時
unsigned long timer=0;

void setup() 
{   
    //距離LED宣告
    pinMode(red,OUTPUT);
    pinMode(green,OUTPUT);
    pinMode(blue,OUTPUT);
    //三軸加速計LED宣告
    pinMode(xred,OUTPUT);
    pinMode(xgreen,OUTPUT);
    pinMode(xblue,OUTPUT);
    //超音波宣告
    pinMode(trig,OUTPUT);
    pinMode(echo,INPUT);
    //三軸加速計宣告
    Wire.begin();
    delay(500);
    xytest.initialize(); 
    //端口開啟
    Serial.begin(9600);
    BT.begin(38400);
}

void loop() 
{   
    //超音波距離計算 v=距離cm
    digitalWrite(trig,1);
    delayMicroseconds(10);
    digitalWrite(trig,0);
    v=(pulseIn(echo, HIGH)/2)/29.1;

    //三軸加速計 計算  x=水平 y=垂直
    xytest.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    x = map(ax,17000,-17000,-180,180);
    y = map(ay,17000,-17000,-180,180);

    //資料處理
    ledif(v); //LED距離if
    mif(x,y); //三軸加速計if
    while (millis() - timer >=200)
    {
        btsend(v,x,y); //藍芽傳送
        serialsend(v,x,y); //Monitor監控
        timer = millis();
    }
}

void ledif(int a)
{
  if (v<=5)
  {
      digitalWrite(red,1);
      digitalWrite(green,0);
      digitalWrite(blue,0);
  }
  else if (v<=10)
  {
      digitalWrite(red,0);
      digitalWrite(blue,0);
      digitalWrite(green,1);
  }
  else if (v<=20)
  {
      digitalWrite(red,0);
      digitalWrite(blue,1);
      digitalWrite(green,0);
  }
  else
  {
      digitalWrite(red,0);
      digitalWrite(green,0);
      digitalWrite(blue,0);
  }  
}

void mif(int a, int b)
{
    a=abs(a);
    b=abs(b);
    if (a>15 && b>15 )
    {
        digitalWrite(xred,1);
        digitalWrite(xgreen,0);
        digitalWrite(xblue,0);
    }
    else if (a>15)
    {
        digitalWrite(xred,0);
        digitalWrite(xgreen,0);
        digitalWrite(xblue,1);
    }
    else if (b>15)
    {
        digitalWrite(xred,0);
        digitalWrite(xgreen,1);
        digitalWrite(xblue,0);
    }
    else
    {
        digitalWrite(xred,0);
        digitalWrite(xgreen,0);
        digitalWrite(xblue,0);
    }
    
}

void btsend(int a,int b, int c)
{
  String textAPP= "";
  textAPP = String(a)+"&";
  textAPP = textAPP+String(b)+"&";
  textAPP = textAPP+String(-b)+"&";
  textAPP = textAPP+String(c)+"&";
  textAPP = textAPP+String(-c)+"&";
  BT.println(textAPP);
  delay(50);
}

void serialsend(int a,int b, int c)
{
    Serial.println(String("*** 超音波距離: ") +a + "CM");
    Serial.println(String("*** 水平傾斜角度:  ") +b + "度" + "\t ****垂直傾斜角度: " + c + "度") ;
    Serial.println("===================================================");
}