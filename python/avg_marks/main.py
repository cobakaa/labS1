f = open("dataset_3363_4.txt", "r")

ph = []
math = []
rus = []

f1 = open("answer.txt", 'w')

for line in f:
    s, m1, m2, m3 = line.split(';')
    ph.append(int(m1))
    math.append(int(m2))
    rus.append(int(m3))

    f1.write(str((int(m1) + int(m2) + int(m3)) / 3) + '\n')

f.close()
sum1 = 0
sum2 = 0
sum3 = 0
for i in range(len(ph)):
    sum1 += ph[i]
    sum2 += math[i]
    sum3 += rus[i]

f1.write(str(sum1 / len(ph)) + ' ' + str(sum2 / len(math)) + ' ' + str(sum3 / len(rus)) + '\n')
f1.close()

