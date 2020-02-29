n,a,b=map(int,input().split())
t=[]
u=[]
s=input().split()
t.append(0)
for i in range(n+1):
    u.append(0)
for i in s:
    t.append(int(i))
ls=[]
an=[]
ls.append(a)
an.append(0)
if a==b:
    print(0)
else:
    ans=-1
    head=0
    tail=0
    while head<=tail:
        if ls[head]+t[ls[head]]<=n and 0==u[ls[head]+t[ls[head]]]:
            tail+=1
            ls.append(ls[head]+t[ls[head]])
            an.append(an[head]+1)
            u[ls[head]+t[ls[head]]]=1
            if ls[tail]==b:
                ans=an[tail]
                break
        if ls[head]-t[ls[head]]>0 and 0==u[ls[head]-t[ls[head]]]:
            tail+=1
            ls.append(ls[head]-t[ls[head]])
            an.append(an[head]+1)
            u[ls[head]-t[ls[head]]]=1
            if ls[tail]==b:
                ans=an[tail]
                break
        head+=1
    print(ans)
