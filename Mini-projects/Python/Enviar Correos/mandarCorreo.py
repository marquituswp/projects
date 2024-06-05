import smtplib  
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

your_email = 'syscurso@gmail.com'
your_password = 'syscurso123'

recipent = 'joelgh@gmail.com'

message = MIMEMultipart()
message['From'] = your_email
message['To'] = recipent
message['Subject'] = 'Email from Python'

body = 'This is a test email sent from a Python script'
message.attach(MIMEText(body, 'plain'))

server = smtplib.SMTP('smtp.gmail.com', 587)
server.starttls()
server.login(your_email, your_password)

server.sendmail(your_email, recipent, message.as_string())
server.quit()
print('Mail sent successfully')