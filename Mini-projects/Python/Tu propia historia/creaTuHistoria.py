import random
import os
vida = 100
puntuacion = 0
armadura = 50

def mostrar_estado():
    print(f' Vida: {vida}. \n Puntuación: {puntuacion}. \n Armadura: {armadura}. \n')

def explorar_habitacion():

    global vida

    enemigo_presente = random.choice([True, False])

    if enemigo_presente:
        print('Enemigo encontrado en la habitación.')
        hablar_con_profesor()
    else:
        print('La habitación está vacía. Sigues explorando.')

def hablar_con_profesor():

    global vida,puntuacion

    print('Te encuentras con un profesor de matemáticas en la habitación.')
    print('El profesor te pregunta sobre las tablas de multiplicar.')

    respuesta_correcta = False

    while not respuesta_correcta and vida > 0:

        multiplicador = random.randint(1,10)
        multiplicando = random.randint(1,10)
        resultado_esperado = multiplicador * multiplicando

        respuesta = input(f'¿Cuánto es {multiplicador} x {multiplicando}?: ')

        if respuesta.isdigit() and int(respuesta) == resultado_esperado:
            print('Respuesta correcta. El profesor está inpresionado y te da 20 puntos.')
            puntuacion += 20
            respuesta_correcta = True
        else:
            print('Respuesta incorrecta. Pierdes 10 puntos de vida. El profesor te pregunta de nuevo.')
            vida -= 10

def evento_aleatorio():

    global vida, puntuacion, armadura

    evento = random.choice(['Encontraste un cofre con tesoros', 'Te caiste y perdiste algo de vida', 'Descubriste un atajo seguro'])

    if evento == 'Encontraste un cofre con tesoros':
        print('¡Encontraste un cofre con tesoros! Obtuviste 20 puntos.')
        puntuacion += 20

    elif evento == 'Te caiste y perdiste algo de vida':
        print('Perdiste -10 de vida y -10 de armadura por caerte en un hoyo.')
        vida -= 10
        armadura -= 10
    elif evento == 'Descubriste un atajo seguro':
        print('Has encontrado un atajo seguro que te lleva a la habitación del jefe final. !Buena suerte¡')
        jugar_piedra_papel_tijera()

def jugar_piedra_papel_tijera():
    
        global vida, puntuacion
    
        print('\n Has llegado a la habitación del jefe final.')
        print('El jefe final te desafía al juego de piedra, papel o tijera.')
    
        opciones = ['piedra', 'papel', 'tijeras']
        
    
        while True:
            while True:
                try:
                    opcion_jugador = input('Elige tu jugada (piedra/papel/tijeras): ').lower()
                    if opcion_jugador not in opciones:
                        raise ValueError
                    break
                except ValueError:
                    print('Opción no válida. Por favor, elige piedra, papel o tijeras.')
            opcion_jefe = random.choice(opciones)
        
            print(f'El jefe final elige {opcion_jefe}.')
            if opcion_jugador == opcion_jefe:
                print('Empate. Intentalo de nuevo.')
            elif (opcion_jugador == 'piedra' and opcion_jefe == 'tijeras') or (opcion_jugador == 'papel' and opcion_jefe == 'piedra') or (opcion_jugador == 'tijeras' and opcion_jefe == 'papel'):
                print('!Ganaste¡ Has derrotado al jefe final.')
                puntuacion += 100
                print('Te has pasado el juego')
            else:
                print('!Perdiste¡ El jefe final te ha derrotado')
                print('¿Deseas volver a intentarlo? (s/n)')
                respuesta = input()
                
                if respuesta == 's':
                    reiniciar_juego()
                    jugar_juego()
                else:
                    print('¡Hasta la próxima!')
                    break

def reiniciar_juego():
    global vida, puntuacion, armadura
    vida = 100
    puntuacion = 0
    armadura = 50


def jugar_juego():

    while vida > 0:

        print('\n Te encuentras en un pasillo del castillo. ')
        mostrar_estado()
        opcion = input('¿Qué deseas hacer?\n 1. Entrar en una habitación. \n 2. Seguir explorando. \n 3. Consultar tu estado. \n 4. Salir del juego. \n Elije una opción (1/2/3/4): ')

        if opcion == '1':
            explorar_habitacion()
        elif opcion == '2':
            evento_aleatorio()
        elif opcion == '3':
            mostrar_estado()
        elif opcion == '4':
            print('Decidiste salir del juego. ¡Hasta la próxima!')
            break
        else:
            if os.name == 'nt':
                os.system('cls')
            else:
                os.system('clear')
            print('Opción no válida. Por favor, elige 1,2,3,4')

        if vida <= 0:
            print('\n¡Has perdido! Tu personaje ha quedado sin vida.')
            mostrar_estado()
        elif puntuacion >= 100:
            print('\n¡Has ganado! Has conseguido una puntuación de 100 puntos. ¡Felicidades!')
            mostrar_estado()
            break
        elif armadura <= 0:
            print('\n Tu armadura está dañada. Has perdido.')
            mostrar_estado()
            break

if __name__ == '__main__':
    jugar_juego()