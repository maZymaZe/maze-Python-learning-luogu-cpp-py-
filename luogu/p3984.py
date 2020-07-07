n,t=map(int,input().split())
pre=0
w=[]
ww=input().split()
for i in range(n):
    w.append(int(ww[i]))
b=w[0]
e=w[0]+t
ans=0
for i in range(1,n):
    if w[i]<e:
        e=w[i]+t
    else:
        ans+=e-b
        b=w[i]
        e=w[i]+t
ans+=e-b
print(ans)