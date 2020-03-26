n=int(input())
t=[]
s=input().split()
for i in s:
    t.append(int(i))
t.sort()
ans=1
f=1
for i in range(n):
    w=t[i]-i
    if w<=0:
        f=0
        break
    ans*=w
    ans%=1000000007
if f==0:
    print(0)
else :
    print(ans)