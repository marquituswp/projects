import random
import os
def generate_password(length):
    chars = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*().,?0123456789'
    password = ''
    for _ in range(length):
        password += random.choice(chars)

    print(password)

if __name__ == '__main__':
    while True:
        try:
            length = int(input('Enter the length of password: '))
            generate_password(length)
            break
        except:
            if os.name == 'nt':
                os.system('cls')
            else:
                os.system('clear')
            print('Enter a valid value')
