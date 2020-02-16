m=0
s=0
f=0
for i in range(1,13) :
    m+=300
    u=input().split()
    m-=int(u[0])
    if m<0 :
        print(-i)
        f=1
        break
    s+=m//100*100
    m%=100
if f==0 :
    print(int(s*1.2+m))