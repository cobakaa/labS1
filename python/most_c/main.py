f = open("dataset_3363_3.txt", "r")

d = {}

for line in f:
    l = line.split()
    l = [i.lower() for i in l]
    for i in l:
        if i in d:
            d[i] += 1
        else:
            d[i] = 1
f.close()

ans = 0
kans = ''
for k, v in d.items():
    if (v > ans) or (v == ans and k < kans):
        kans = k
        ans = v

print(kans, ans)
