#include <Arduino.h>

//腳位 
const int data=0,SH=1,ST=2,ba=3,bb=4;
//變數
int a=0,b=0,mode_delay=0,cancel_delay=0,mode=0,
    animation_time=100,time_count=0,sleep=0;
//顯示數字
int num[10]={4,158,34,10,152,72,64,30,0,8};
void setup()
{
  //pinMode
  pinMode(data,OUTPUT);
  pinMode(SH,OUTPUT);
  pinMode(ST,OUTPUT);
  pinMode(ba,OUTPUT);
  pinMode(bb,OUTPUT);
  //開機動畫
  ns(126,126);
  delay(animation_time);
  ns(190,190);
  delay(animation_time);
  ns(222,222);
  delay(animation_time);
  ns(238,238);
  delay(animation_time);
  ns(246,246);
  delay(animation_time);
  ns(252,252);
  delay(animation_time);
  ns(250,250);
  delay(animation_time);
  ns(num[0],num[0]);
}

void loop()
{
  //休眠模式
  if(sleep!=3000)
  {
    sleep+=3000;
  }
  else if(sleep=3000)
  {
    ns(254,253);
    delay(200);
    ns(254,254);
    delay(3000);
    if(digitalRead(ba) || digitalRead(bb))
    {
      sleep=0;
    }
  }
  //電源供應開始
  cancel_delay=0;
  while(digitalRead(ba)==1 && digitalRead(bb)==1)
    {
      sleep=0;
      cancel_delay++;
      if(cancel_delay==30 && a+b!=0)
      {
        time();
        break;
      }
      else if(cancel_delay==30)
      {
        start();
        break;
      }
      delay(50);
    }
  delay(30);
  //A按鈕
  mode_delay=0; 
  while(digitalRead(ba)==1 && digitalRead(bb)==0)
    {
      sleep=0;
      mode_delay++;
      if(mode_delay>5 && mode==0)
      {
        ns(154,240);
        delay(500);
        digitalWrite(ST, LOW);
        mode++;
        ns(num[0],num[0]);
        a=0;
        b=0;
        break;
      }
      //更改計時單位-小時
      else if(mode==1 && mode_delay==1)
      {
        hour();        
      }
      else if(mode==0 && mode_delay==1)
      {
        minute();
      }
      delay(200);
    }
  delay(30);
  //B按鈕
  mode_delay=0; 
  while(digitalRead(ba)==0 && digitalRead(bb)==1)
    {
      sleep=0;
      mode_delay++;
      if(mode_delay>5 && mode==1)
      {
        ns(20,20);
        delay(500);
        digitalWrite(ST, LOW);
        mode--;
        ns(num[0],num[0]);
        a=0;
        b=0;
        break;
      }
      //更改計時單位-小時
      else if(mode==1 && mode_delay==1)
      {
        hour();
      }
      else if(mode==0 && mode_delay==1)
      {
        minute();
      }
      delay(200);
    }
}
//電源供應模式
void start()
{
  cancel_delay=0;
  ns(251,250);
  //退出
  while (cancel_delay!=15)
  {
    cancel_delay=0;
    while(digitalRead(ba) && digitalRead(bb))
    {
      cancel_delay++;
      if(cancel_delay==15)
      {
        break;
      }
      delay(100);
    }
  }
  ns(num[0],num[0]);
}
//計時模式
void time()
{
  ns(0,0);
  delay(500);
  ns(num[a]+1,num[b]);
  cancel_delay=0;
  switch(mode)
  {
    //小時
    case 1:
      while(a+b*10!=0)
        {
          time_count=0;
          while(time_count!=3600)
          {
            time_count++;
            cancel_delay=0;
            ns(num[a]+1,num[b]);
            while(digitalRead(ba) && digitalRead(bb))
            {
              cancel_delay++;
              if(cancel_delay==15)
              {
                a=0;
                b=0;
                time_count=3600;
                break;
              }
              delay(100);
            }
            delay(500);
            ns(num[a]+1,num[b]-1);
            delay(500);
          }
          a--;
          if(a==-1)
          {
            b--;
            a=9;
          }
          if(b==-1)
          {
            b++;
            a=0;
            break;
          }
          ns(num[a]+1,num[b]+1);
        }
        
    //分鐘
    case 0:
      while(a+b*10!=0)
        {
          time_count=0;
          while(time_count!=60)
          {
            time_count++;
            cancel_delay=0;
            ns(num[a]+1,num[b]);
            while(digitalRead(ba) && digitalRead(bb))
            {
              cancel_delay++;
              if(cancel_delay==15)
              {
                a=0;
                b=0;
                time_count=60;
                break;
              }
              delay(100);
            }
            delay(500);
            ns(num[a]+1,num[b]-1);
            delay(500);
          }
          a--;
          if(a==-1)
          {
            b--;
            a=9;
          }
          if(b==-1)
          {
            b++;
            a=0;
            break;
          }
          ns(num[a]+1,num[b]+1);
  }
  ns(num[0],num[0]);
}
}
//顯視器控制
void ns(int a,int b)
{
  digitalWrite(ST, LOW);
  shiftOut(data, SH, LSBFIRST,a);
  shiftOut(data, SH, LSBFIRST,b+1);
  digitalWrite(ST, HIGH);
}
//分鐘設定
void minute()
{
  if(digitalRead(ba)==1 && digitalRead(bb)==0 && a!=10 && b!=9)
  {
    a+=10;
  }
  if(digitalRead(ba)==0 && digitalRead(bb)==1 && b!=0)
  {
    b-=1;
  }
  if(a==10)
  {
    b++;
    a=0;
  }
  ns(num[a],num[b]);
}
//小時設定
void hour()
{
  if(digitalRead(ba)==1 && digitalRead(bb)==0 && a!=10 && b!=9)
  {
    a++;
  }
  if(a==10)
  {
    b++;
    a=0;
  }
  if(digitalRead(ba)==0 && digitalRead(bb)==1 && a!=-1 && b!=-1)
  {
    a--;
  }
  if(a==-1)
  {
    b--;
    a=9;
  }
  if(b==-1)
  {
    b++;
    a=0;
  }
  ns(num[a],num[b]);
}
