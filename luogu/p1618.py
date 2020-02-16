a,b,d=map(int,input().split())
def tes(x):
    global a,b,d
    f=1
    c=[]
    for i in range(13):
        c.append(0)
    u=a*x
    c[u%10]+=1
    u//=10
    c[u%10]+=1
    u//=10
    c[u]+=1
    u=b*x
    c[u%10]+=1
    u//=10
    c[u%10]+=1
    u//=10
    c[u]+=1
    u=d*x
    c[u%10]+=1
    u//=10
    c[u%10]+=1
    u//=10
    c[u]+=1
    for i in range(1,10):
        if c[i]!=1 :
            f=0
    return f  
fg=0  
for i in range(1,1000):
    if  d*i<1000 and a*i>99 and a*i<1000 and tes(i)==1 :
        print(a*i,b*i,d*i)
        fg=1
if fg==0:
    print('No!!!')