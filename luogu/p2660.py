a,b=map(int,input().split())
ans=0
while a!=b and a!=0 and b!=0:
    if b>a:
        a,b=b,a
    ans+=(a//b)*4*b
    a,b=b,a%b
if a==b and a!=0:
    ans+=a*4
print(ans)