import shutil
import sys
import os

def gusano():
    # Check if the user has entered the correct number of arguments
    if len(sys.argv) ==2:
        for num in range(0, int(sys.argv[1])):
            shutil.copy(sys.argv[0], sys.argv[0] + f'{num}.py')

        print(f"File {sys.argv[0]} copied to {sys.argv[0]}")
    else:
        print('Envia dos parámetros')

    

if __name__ == "__main__":
    gusano()

    