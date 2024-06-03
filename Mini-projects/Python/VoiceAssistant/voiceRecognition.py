#Use virtual env with pyhton 3.10 version
#Install SpeechRecognition with pip install SpeechRecognition
#Install pyttsx3 with pip install pyttsx3
#Install PyAudio with pip install PyAudio

#https://www.amazon.es/s?k=

import speech_recognition as sr
import webbrowser
import pyttsx3

recognizer = sr.Recognizer()

engine = pyttsx3.init()


def talk():

    mic = sr.Microphone()
    with mic as source:

        audio = recognizer.listen(source)

    try:

        text = recognizer.recognize_google(audio,language = 'ES')
    
    except sr.UnknownValueError:
            print("Sorry, I did not understand that.")
            return ""
    except sr.RequestError:
        print("Sorry, my speech service is down.")
        return ""

    print(f'Me has dicho: {text}')
    return text.lower()

if 'amazon' in talk():
    
    engine.say('Qué quieres comprar en amazon')

    engine.runAndWait()
    text = talk()
    print(f'Me has dicho: {text}')
    try:
        webbrowser.open(f'https://www.amazon.es/s?k={text}')

    except Exception as e:
        print(e)