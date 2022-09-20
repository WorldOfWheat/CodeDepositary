from selenium import webdriver
from selenium.webdriver.support.ui import Select
from tkinter import messagebox as mb
from pyautogui import press
import tkinter as tk
import tkinter.messagebox
import pyscreenshot as ImageGrab
import pyautogui
import pyperclip
import csv
import time

#start
url = ''
driver = webdriver.Chrome()  
driver.get(url)
time.sleep(0.5)
driver.maximize_window()
time.sleep(0.5)

#keyin_date
date=time.strftime('%Y/%m/%d',time.localtime())

pyautogui.click(665,442,button='left')
time.sleep(0.2)
pyautogui.typewrite(date)
time.sleep(0.2)

#keyin_number
pyautogui.click(687,595,button='left')
time.sleep(0.2)
pyautogui.typewrite("34")
time.sleep(0.2)

#keyin_name
pyautogui.click(679,743,button='left')
time.sleep(0.2)
pyperclip.copy('') #姓名
pyautogui.keyDown('ctrl')
pyautogui.press('v')
pyautogui.keyUp('ctrl')
time.sleep(0.2)

#page_down
press('pgdn')
time.sleep(0.2)

#lesson_object
lesson=[]
day=time.strftime('%w',time.localtime())
file=r'C:\Users\a3028\Desktop\upload_time\lesson\lesson.csv'
with open(file) as csvFile:
    read = csv.DictReader(csvFile)
    data = list(read)
    for line in data:
        lesson.append(line[day])

#lesson_keyin
#1
pyautogui.click(691,169,button='left')
time.sleep(0.2)
pyperclip.copy(lesson[0])
pyautogui.keyDown('ctrl')
pyautogui.press('v')
pyautogui.keyUp('ctrl')
time.sleep(0.2)
#2
pyautogui.click(683,544,button='left')
time.sleep(0.2)
pyperclip.copy(lesson[1])
pyautogui.keyDown('ctrl')
pyautogui.press('v')
pyautogui.keyUp('ctrl')
time.sleep(0.2)
#3
pyautogui.click(687,939,button='left')
time.sleep(0.2)
pyperclip.copy(lesson[2])
pyautogui.keyDown('ctrl')
pyautogui.press('v')
pyautogui.keyUp('ctrl')
time.sleep(0.2)

#page_down
press('pgdn')
time.sleep(0.2)

#4
pyautogui.click(693,512,button='left')
time.sleep(0.2)
pyperclip.copy(lesson[3])
pyautogui.keyDown('ctrl')
pyautogui.press('v')
pyautogui.keyUp('ctrl')
time.sleep(0.2)

#5
pyautogui.click(675,893,button='left')
time.sleep(0.2)
pyperclip.copy(lesson[4])
pyautogui.keyDown('ctrl')
pyautogui.press('v')
pyautogui.keyUp('ctrl')
time.sleep(0.2)

#page_down
press('pgdn')
time.sleep(0.2)

#6
pyautogui.click(693,471,button='left')
time.sleep(0.2)
pyperclip.copy(lesson[5])
pyautogui.keyDown('ctrl')
pyautogui.press('v')
pyautogui.keyUp('ctrl')
time.sleep(0.2)
#7
pyautogui.click(683,853,button='left')
time.sleep(0.2)
pyperclip.copy(lesson[6])
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