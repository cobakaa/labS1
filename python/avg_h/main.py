f = open("dataset_3380_5.txt", 'r')

d = {}

for line in f:
    cl, s, h = line.split()
    if cl not in d:
        d[cl] = [int(h), 1]
    else:
        d[cl][0] += int(h)
        d[cl][1] += 1
f.close()

f1 = open("answer.txt", 'a')

for i in range(1, 12):
    if str(i) in d:
        f1.write(str(i) + ' ' + str(d[str(i)][0] / d[str(i)][1]) + '\n')
    else:
        f1.write(str(i) + ' -\n')
f1.close()
