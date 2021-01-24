def yh(max):
    l=[1]
    n=1
    while n<=max :
        yield l
        t=1
        for i in range(1,n):
            p=l[i]
            l[i]=t+l[i]
            t=p
        l.append(1)
        n+=1
for i in yh(5):
    print(i)