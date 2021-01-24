import time
import random
cnt = 0
n = int(input())
# n=1000000
random.seed()
timestart = time.time()
for i in range(n):
    a = random.uniform(1, 4096)
    b = random.uniform(1, 4096)
    c = 4096
    if a*a+b*b <= c*c:
        cnt += 1
print(4.0*cnt/n)
timeend = time.time()
print((timeend-timestart)*1000)
#input()
