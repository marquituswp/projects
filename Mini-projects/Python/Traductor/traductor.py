from translate import Translator

translator = Translator(from_lang="spanish", to_lang="english")

txt = input("Introduce el texto a traducir: ")

res = translator.translate(txt)

print(res)