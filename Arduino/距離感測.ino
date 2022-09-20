int a=4,b=3,
r=7,g=8,bl=9,
di=0,in=2;

void setup()
{
  Serial.begin(115200);
  //燈
  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(bl,OUTPUT);
  //距離
  pinMode(a,OUTPUT);
  pinMode(b,INPUT);
  //按鈕
  pinMode(in,INPUT);
}

void loop()
{
  //按鈕值讀取
  int inread=digitalRead(in);
  //距離讀取
  digitalWrite(a,1);
  delayMicroseconds(10);
  digitalWrite(a,0);
  di=(pulseIn(b, HIGH)/2)/29.1;
  //回傳值
  Serial.println(inread);
  //按鈕EMS
  if (inread==1)
  {
    digitalWrite(r,0);
    digitalWrite(g,0);
    digitalWrite(bl,255);
  }
  //紅燈
  else if (di<=20)
  {
    digitalWrite(bl,0);
    digitalWrite(g,0);
    digitalWrite(r,255);
    delay(100);
    //距離小於五
    while (di<=5)
    {
      digitalWrite(r,255);
    }
    digitalWrite(r,0);
    delay(100);
  }
  //正常模式
  else
  {
    digitalWrite(r,0);
    digitalWrite(bl,0);
    digitalWrite(g,255);
  }
}