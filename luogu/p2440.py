n,k= map(int, input().split())
t=[]
for i in range(n):
    t.append(int(input()))
l,r=0,100000001
while l+1<r:
    tot=0
    mid=(l+r)//2
    for i in t:
        if mid>0:
            tot+=i//mid
        else:
            l=0
            break
    if tot>=k:
        l=mid
    else:
        r=mid
print(l)