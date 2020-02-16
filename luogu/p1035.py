s=0
k=int(input())
for i in range(1,100000000000):
    s+=1/i
    if s>k :
        print(i)
        break
