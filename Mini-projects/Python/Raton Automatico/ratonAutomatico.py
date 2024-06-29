import pyautogui as botMouse
import webbrowser as web
import random
import time


web.open('https://www.youtube.com/@HiClavero')

while True:
    print(botMouse.position())
    x= 2496
    y = 522
    botMouse.moveTo(x,y,0.5)
    time.sleep(4)
    botMouse.click()