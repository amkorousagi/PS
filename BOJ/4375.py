import sys

for n in sys.stdin:
    n = int(n)
    try:
        a = 0
        i=1
        while(True):
            a = a * 10 + 1
            if a % n == 0:
                print(i)
                break
            i = i + 1	
    except StopIteration:
        break
		