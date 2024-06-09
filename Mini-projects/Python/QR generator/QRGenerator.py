import qrcode
import os

os.chdir('Mini-projects/Python/QR generator') 

qr = qrcode.QRCode(version = 1,
                   error_correction = qrcode.constants.ERROR_CORRECT_L,
                   box_size = 7,
                   border = 2)

qr.add_data('https://www.youtube.com/channel/UCaWpNQGdh9Gnzsn7pulspnw') # Insert your direction
qr.make(fit = True)

img = qr.make_image(fill_color = 'black', back_color = 'white')

img.save('QR.png')