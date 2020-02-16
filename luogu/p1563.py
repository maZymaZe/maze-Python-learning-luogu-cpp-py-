n,m=map(int,input().split())
f=[]
nm=[]
for i in range(n):
    t1,t2=input().split()
    f.append(int(t1))
    nm.append(t2)
p=0
for i in range(m):
    t3,t4=map(int,input().split())
    if t3!=f[p]:
        p+=t4
    else :
        p-=t4
    p%=n
print(nm[p])
