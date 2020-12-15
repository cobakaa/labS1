import requests

f = requests.get('https://stepic.org/media/attachments/course67/3.6.2/168.txt')
text = f.text
print(len(text.splitlines()))