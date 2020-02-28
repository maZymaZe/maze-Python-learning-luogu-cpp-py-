n=int(input())
i=n//2+1
while i>1:
    if i%2==0:
        if (n+i//2)%i==0:
            if n//i-(i//2-1)>=0:
                print("%d %d"%(n//i-(i//2-1),n//i-(i//2-1)+i-1))
    else:
        if n%i==0:
            if n//i-i//2>=0:
                print("%d %d"%(n//i-i//2,n//i+i//2))
    i-=1
