#Use virtual env with pyhton 3.10 version
#Install SpeechRecognition with pip install SpeechRecognition
#Install pyttsx3 with pip install pyttsx3
#Install PyAudio with pip install PyAudio

#https://www.amazon.es/s?k=

import speech_recognition as sr
import webbrowser
import pyttsx3
import time

def talk():

    
    print('Escuchando...')
    with sr.Microphone() as source:

        audio = recognizer.listen(source)
        
    try:
        print('Reconociendo...')
        text = recognizer.recognize_google(audio, language='es-ES')
        print(f'Has dicho: {text}')
    except sr.UnknownValueError:
            print("Sorry, I did not understand that.")
            return ""
    except sr.RequestError:
        print("Sorry, my speech service is down.")
        return ""
    return text.lower()

if __name__ == '__main__':
    recognizer = sr.Recognizer()
    engine = pyttsx3.init()
    engine.setProperty('rate', 150)
    
    while True:
        engine.say('Hola, ¿en qué puedo ayudarte?')
        engine.runAndWait()
        if 'amazon' in talk():
            
            engine.say('Qué quieres comprar en amazon')

            engine.runAndWait()

            
            text = talk()
            try:
                engine.say(f'Buscando {text} en amazon')
                engine.runAndWait()
                webbrowser.open(f'https://www.amazon.es/s?k={text}')
                
                time.sleep(3)
                engine.say('¿Puedo ayudarte en algo más?')
                engine.runAndWait()


                text = talk()
                if 'no' in text:
                    engine.say('Hasta luego')
                    engine.runAndWait()
                    break
            except Exception as e:
                print(e)

