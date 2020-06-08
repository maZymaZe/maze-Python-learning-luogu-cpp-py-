n=int(input())
s=input().split()
ans=int(s[0])
pre=ans
for i in range(1,n):
    if int(s[i])>pre:
        ans+=int(s[i])-pre
    pre=int(s[i])
print(ans)