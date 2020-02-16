from math import ceil
s=input().split()
n=int(s[0])
m=100000001
for i in range(1,4):
    a,b=map(int,input().split())
    m=min(m,ceil(n/a)*b)
print(int(m))