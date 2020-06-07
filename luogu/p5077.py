n= int(input())
n*=2
a=99999999999999
b=0
t1=0
t2=0
for i in range(1,2000000):
    if n%i == 0:
        t1=n//i
        t2=i-1
        if t1%2==t2%2 and t1>t2:
            if a>(t1-t2)//2:
                a=(t1-t2)//2
                b=(t1+t2)//2
print("{} {}".format(a,b))
