x = int(input())
#m = [i for i in range(1, x * x + 1)]

mm = [[0 for i in range(x)] for j in range(x)]
k = 1
i = 0
j = 0
c = 0
while (k <= x * x):
    while (j < x - c):
        mm[i][j] = k
        k += 1
        j += 1
    while (i + 1 < x - c):
        mm[i + 1][j - 1] = k
        k += 1
        i += 1
    while (j - 1 > 0 + c):
        mm[i][j - 2] = k
        k += 1
        j -= 1
    while (i - 1 > 0 + c):
        mm[i - 1][j - 1] = k
        k += 1
        i -= 1
    c += 1

for i in mm:
    for j in i:
        print(j, end=' ')
    print()