def tes(x):
    f=1
    c=[]
    for i in range(13):
        c.append(0)
    u=x
    c[u%10]+=1
    u//=10
    c[u%10]+=1
    u//=10
    c[u]+=1
    u=2*x
    c[u%10]+=1
    u//=10
    c[u%10]+=1
    u//=10
    c[u]+=1
    u=3*x
    c[u%10]+=1
    u//=10
    c[u%10]+=1
    u//=10
    c[u]+=1
    for i in range(1,10):
        if c[i]!=1 :
            f=0
    return f    
for i in range(123,330):
    if tes(i)==1 :
        print(i,2*i,3*i)
