import os
import time
from playsound import playsound

def alarm(minutes,seconds):

    sound_path = os.path.join(os.path.dirname(__file__), 'alarma_python.mp3')

    total_seconds = minutes * 60 + seconds

    print(f'La arama sonará en {minutes} minutos y {seconds} segundos.')

    time.sleep(total_seconds)

    playsound(sound_path)


if __name__ == '__main__':

    while True:
        try:

            minutes = int(input('Ingresa los minutos de la alarma: '))
            seconds = int(input('Ingresa los segundos de la alarma: '))

            alarm(minutes,seconds)
            break
        except:
            if os.name == 'nt':
                os.system('cls')
            else:
                os.system('clear')
            print('Ingresa un valor válido')
            