a=[1,1]
for i in range(2,101):
    a.append(a[i-1]*i)
n=int(input())
for i in range(n):
    t=int(input())
    print(a[t])