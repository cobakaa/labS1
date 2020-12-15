import requests
# import sys

f = open("dataset_3378_3.txt", 'r')
line = f.readline()[:-1]
f.close()
t = ''
text = requests.get(line).text
k = 0
while text[0:2] != "We":
    text = requests.get('https://stepic.org/media/attachments/course67/3.6.3/' + text).text
    k += 1
    print(k)

f1 = open("answer.txt", 'w')
f1.write(text)
f1.close()
