global c
c=0
n,x=map(int,input().split())
def ct(t):
    global c
    while t!=0 :
        if t%10==x:
            c+=1
        t//=10
for i in range(1,n+1):
    ct(i)
print(c)