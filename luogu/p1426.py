s,x=map(float,input().split())
p=0.0
b=7.0
c='n'
while(p<=200):
    if p>=s-x and p<=s+x:
        if p+b<=s+x:
            c='y'
            break
    p+=b
    b*=0.98
print(c)
