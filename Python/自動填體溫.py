from selenium import webdriver
from selenium.webdriver.support.ui import Select
from tkinter import messagebox as mb
from pyautogui import press
import tkinter as tk
import tkinter.messagebox
import pyscreenshot as ImageGrab
import PIL
import pyautogui
import pyperclip
import random
import math
import time

#start
url = ''
driver = webdriver.Chrome()  
driver.get(url)
time.sleep(0.5)
driver.maximize_window()
time.sleep(0.5)

#check_box
pyautogui.click(701,351,button='left')
time.sleep(0.2)
pyautogui.click(709,466,button='left')
time.sleep(0.2)

#keyin

pyautogui.click(687,539,button='left')
time.sleep(0.2)
pyautogui.typewrite("34")
time.sleep(0.2)

pyautogui.click(689,689,button='left')
time.sleep(0.2)
pyperclip.copy('') #姓名
pyautogui.keyDown('ctrl')
pyautogui.press('v')
pyautogui.keyUp('ctrl')
time.sleep(0.5)

#temp_enterence
a=random.randint(35,36)
b=random.random()

while not a+b>35.5 or not a+b<36.5:
    a=random.randint(35,36)
    b=random.random()

pyautogui.click(685,858,button='left')
time.sleep(0.2)
pyperclip.copy(str(round(a+b,1)))
pyautogui.keyDown('ctrl')
pyautogui.press('v')
pyautogui.keyUp('ctrl')
time.sleep(0.2)

#screenshot
tk.messagebox.showwarning("確認視窗", "！所有資料已填寫完成！")
tk.messagebox.showwarning("確認視窗", "！確認關閉並截圖！")
upload_time=time.strftime("%Y年%m月%d日%H時%M分%S秒",time.localtime())
time.sleep(0.5)
image = ImageGrab.grab()
image.save(str(upload_time)+'.png')

#close
driver.close()