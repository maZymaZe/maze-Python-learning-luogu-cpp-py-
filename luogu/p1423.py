s=0
b=2
k=float(input())
for i in range(1,100000000000):
    s+=b
    b*=0.98
    if s>=k :
        print(i)
        break
 