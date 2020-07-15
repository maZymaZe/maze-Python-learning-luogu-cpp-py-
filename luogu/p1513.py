from math import sqrt
ip=input().split()
n=int(ip[0])
r=float(ip[1])
t=[[0.0,0.0]for _ in range(n+1)]
ans=2*3.14159*r
for i in range(n):
    t[i][0],t[i][1]=map(float,input().split())
    if i>=1:
        ans+=sqrt((t[i-1][0]-t[i][0])**2+(t[i-1][1]-t[i][1])**2)
ans+=sqrt((t[0][0]-t[n-1][0])**2+(t[0][1]-t[n-1][1])**2)
print(round(ans,2))