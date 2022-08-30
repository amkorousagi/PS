a = input().split()
b = input()

if int(b)+int(a[2]) < 60:
    print(f'{a[0]} {a[1]} {int(b)+int(a[2])}')
elif (((int(b)+int(a[2]))//60) + int(a[1])) < 60:
    print(f'{a[0]} {((int(b)+int(a[2]))//60) + int(a[1])} {(int(b)+int(a[2]))%60}')
else:
    print(f'{(int(a[0])+(((int(b)+int(a[2]))//60) + int(a[1]))//60)%24} {(((int(b)+int(a[2]))//60) + int(a[1]))%60} {(int(b)+int(a[2]))%60}')
