mk=[6,2,5,5,4,5,6,3,7,6]
def f(x,s):
    if x<10:
        return s+mk[x]
    else :
        return f(x//10,s+mk[x%10])
n=int(input())
n-=4
g=[]
for i in range(2049):
    g.append(f(i,0))
c=0
for i in range(1024):
    for j in range(i+1):
        if g[i]+g[j]+g[i+j]==n:
            if i==j:
                c+=1
            else :
                c+=2                
print(c)