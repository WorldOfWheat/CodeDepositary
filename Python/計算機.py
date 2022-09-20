class math:
    x1=int(input("請輸入數字一  "))
    print("\n基本符號: + - * /\n次方符號: **\n平方根符號: */\n和的平方: +*\n差的平方: -*\n平方差: *-\n畢氏定理 - 斜邊: *+*\n畢氏定理 - 股長: *-*\n ")
    x3=input("請輸入計算符號  ")
    print("")
    x2=int(input("請輸入數字二  "))
def math2():
    if math.x3=="+":
        print("\n",math.x1+math.x2) 
    elif math.x3=="-":
        print("\n",math.x1-math.x2)
    elif math.x3=="*":
        print("\n",math.x1*math.x2)
    elif math.x3=="/":
        print("\n",math.x1/math.x2)
    elif math.x3=="**":
        print("\n",math.x1**math.x2)
    elif math.x3=="*/":
        print("\n",math.x1**0.5)
    elif math.x3=="+*":
        print("\n",math.x1**2+math.x1*math.x2*2+math.x2**2)
    elif math.x3=="-*":
        print("\n",math.x1**2-math.x1*math.x2*2+math.x2**2)
    elif math.x3=="*-":
        print("\n",(math.x1+math.x2)*(math.x1-math.x2))
    elif math.x3=="*+*":
        print("\n",(math.x1**2+x2**2)**0.5)
    elif math.x3=="*-*":
        print("\n",(math.x1**2-math.x2**2)**0.5)
    else:
        print("\n錯誤的運算符號")
math2()
print("\n點擊 Enter 已關閉...")
input("")