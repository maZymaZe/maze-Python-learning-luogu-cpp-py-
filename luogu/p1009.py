n=int(input())
w=1
ans=0
for i in range(1,n+1):
    w*=i
    ans+=w
print(ans)