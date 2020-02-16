def ip(x):
    f = 1
    if x == 2 or x == 3:
        return 1
    elif x == 1 or x == 4:
        return 0
    else:
        for i in range(2, int(x**0.5)+1):
            if x % i == 0:
                f = 0
                break
    return f
t=[]
def fi(n):
    global t
    if n==1:
        for i in range(2,10):
            t.append(i)
    if n==2:
        t.append(11)
    if n==3:
        for i in range(5):
            for j in range(10):
                t.append(101*(2*i+1)+j*10)
    if n==4:
        for i in range(5):
            for j in range(10):
                t.append(1001*(2*i+1)+j*110)
    if n==5:
        for i in range(5):
            for j in range(10):
                for k in range(10):
                    t.append(10001*(2*i+1)+j*1010+k*100)
    if n==6:
        for i in range(5):
            for j in range(10):
                for k in range(10):
                    t.append(100001*(2*i+1)+j*10010+k*1100)
    if n==7:
        for i in range(5):
            for j in range(10):
                for k in range(10):
                    for h in range(10):
                        t.append(1000001*(2*i+1)+j*100010+k*10100+h*1000)
    if n==8:
        for i in range(5):
            for j in range(10):
                for k in range(10):
                    for h in range(10):
                        t.append(10000001*(2*i+1)+j*1000010+k*100100+h*11000)
    if n==9:
        pass
a,b=map(int,input().split())
for i in range(len(str(a)),len(str(b))+1):
    fi(i)
for i in t:
    if i<=b and i>=a:
        if ip(i)==1:
            print(i)

    
    
        



            

            

