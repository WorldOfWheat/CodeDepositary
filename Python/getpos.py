from pyautogui import press
import pyautogui
import time

pos=pyautogui.position()
print(pos)

f = open(r'C:\Users\a3028\Desktop\pos.txt','a')
f.write(str(pos))
f.write("\n")
