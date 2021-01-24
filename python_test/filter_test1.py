def  dh(n):
    l=str(n)
    if len(l)%2==0 :
        for i in range(1,len(l)//2+1):
            if l[i-1]!=l[len(l)-i] :
                return 0
    else :
        for i in range(1,(len(l)-1)//2+1):
            if l[i-1]!=l[len(l)-i]:
                return 0
    return 1

s=list(range(1,10001))
t=list(filter(dh,s))
print(t)

