f = open('dataset_3363_2.txt', "r")
for line in f:
    k = ''
    l = line[0]
    for i in line[1:]:
        if i.isnumeric():
            k += i
            continue

        f2 = open("answer.txt", "a")
        f2.write(l * int(k))
        f2.close()
        k = ''
        l = i

f.close()
