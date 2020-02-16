n, k = map(int, input().split())
r = input().split()
t = []
for i in range(n):
    t.append(int(r[i]))
u = []
for i in range(30):
    u.append(0)
global c
c = 0


def ip(x):
    f = 1
    if x==2 or x==3 or x==5:
        return 1
    elif x==1:
        return 0
    else  :  
        for i in range(2, int(x**0.5)+1):
            if x % i == 0:
                f = 0
                break
        return f


def ct(su, nb, t, j):
    global c
    if nb == k:
        if ip(su) == 1:
            c += 1
    else:
        for i in range(j, n):
            if u[i] == 0:
                u[i] = 1
                ct(su+t[i], nb+1, t, i+1)
                u[i] = 0


ct(0, 0, t, 0)
if k<=0 :
    print(0)
else :
    print(c)

