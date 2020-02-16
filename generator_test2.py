def fib(max):
    n=1
    a=1
    b=1
    while n<=max :
        yield a
        (a,b)=(b,a+b)
        n+=1
    print("end")

for i in fib(10) :
    print(i)
