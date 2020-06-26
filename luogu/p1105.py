n=int(input())
h=[]
l=[]
r=[]
for i in range(n):
    H, L, R=map(int,input().split())
    h.append(H)
    l.append(L)
    r.append(R)
for i in range(n):
    ll=0
    rr=0
    ml=-1
    mr=-1
    for j in range(n):
        if l[j]<l[i] and r[j]>l[i] and h[j]>ml and h[j]<h[i]:
            ll=j+1
            ml=h[j]
    for j in range(n):
        if l[j]<r[i] and r[j]>r[i] and h[j]>mr and h[j]<h[i]:
            rr=j+1
            mr=h[j]
    print(ll,rr)
    