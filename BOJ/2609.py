n = input().split()
a = int(n[0])
b = int(n[1])

if a < b:
    t = a
    a = b
    b = t

# a >= b == true

maxd = 0
for i in range(1,a+1):
    if a%i == 0 and b%i ==0:
        maxd = i

print(maxd)
print((a//maxd)*(b//maxd)*maxd)