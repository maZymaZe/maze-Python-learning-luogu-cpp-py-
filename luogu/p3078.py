n=int(input())
pre=0
ans=0
for i in range(n):
    t=int(input())
    if t>pre:
        ans+=t-pre
    pre=t
print(ans)