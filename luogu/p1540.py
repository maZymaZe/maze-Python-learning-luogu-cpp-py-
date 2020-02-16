m,n=map(int,input().split())
t=[]
for i in range(m):
    t.append(-1)
p=0
c=0
d=input().split()
for i in d:
    w=int(i)
    if not(w in t):
        t[p]=w
        p+=1
        if p==m:
            p=0
        c+=1
print(c)