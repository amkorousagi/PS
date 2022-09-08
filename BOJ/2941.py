s = input()

target = ['dz=','c=','c-','d-','lj','nj','s=','z=']
ss = 0
for i in target:
    s = s.replace(i,'*')

print(len(s))