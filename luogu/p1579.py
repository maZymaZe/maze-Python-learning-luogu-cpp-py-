def ip(x):
    if x==2 or x==3:
        return 1
    else:
        f=1
        for i in range(2,int(x**0.5)+1):
            if x%i==0:
                f=0
                break
        return f
t=[]
o=[]
for i in range(20005):
    t.append(0)
for i in range(2,20001):
    if ip(i)==1:
       t[i]=1
       o.append(i)
n=int(input())
b=0
for i in o:
    for j in o:
        if n-i-j>1 and t[n-i-j]==1:
            print(i,j,n-i-j)
            b=1
            break
    if b==1:
        break