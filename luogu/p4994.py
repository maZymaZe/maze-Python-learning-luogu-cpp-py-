m=int(input())
a,b=1,1
n=1
while 1:
    if a%m==0 and b%m==1:
        print(n)
        break
    else:
        a,b=b,(a+b)%m
        n+=1