idx = 0
mmax = 0
for i in range(9):
    a = int(input())
    if a > mmax:
        idx = i
        mmax = a


print(mmax)
print(idx+1)