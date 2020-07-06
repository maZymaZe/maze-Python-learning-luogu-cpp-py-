n=int(input())
t=[]
for i in range(n):
    ttt,tt=map(int,input().split())
    t.append(tt)
t.sort()
ttt=t[n//2]
ans=0
for i in t:
    ans+=abs(i-ttt)
print(ans)