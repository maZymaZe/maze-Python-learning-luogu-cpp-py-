n = int(input())
f = []
t = input().split()
for i in range(n):
    f.append(int(t[i]))
for i in range(n):
    c = 0
    for j in range(0, i):
       if f[j] < f[i]:
           c += 1
    print(c,end=' ') 
