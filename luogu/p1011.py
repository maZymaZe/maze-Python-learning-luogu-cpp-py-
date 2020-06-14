a,n,m,x=map(int,input().split())
ca=[0,1,1]
ct=[0,0,0]
ba=[0,1,0]
bt=[0,0,1]
for i in range(3,n):
    ba.append(ba[i-1]+ba[i-2])
    ca.append(ba[i-2]+ca[i-1])
    bt.append(bt[i-1]+bt[i-2])
    ct.append(bt[i-2]+ct[i-1])
t=(m-ca[n-1]*a)//ct[n-1]
print(ca[x]*a+ct[x]*t)