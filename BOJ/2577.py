a = int(input())
b = int(input())
c = int(input())

s = str(a*b*c)

cnt = list()
for i in range(10):
    cnt.append(0)

for i in range(len(s)):
    for j in range(10):
        if s[i] == str(j):
            cnt[j] +=1

for i in range(10):
    print(cnt[i])