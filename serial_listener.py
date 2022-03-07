import serial
import time
import pyautogui

ArduinoSerial = serial.Serial('/dev/ttyACM0',9600)
time.sleep(2)

n = 3

def scroll_up(n):
    pyautogui.scroll(n)


def scroll_down(n):
    pyautogui.scroll(-n)


while 1:
    input = str (ArduinoSerial.readline())
    print(input)

    if 'Scroll Up' in input:
        scroll_up(n)

    if 'Scroll Down' in input:
        scroll_down(n)

    input = ""
