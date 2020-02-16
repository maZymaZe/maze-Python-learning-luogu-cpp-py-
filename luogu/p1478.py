n,s=map(int,input().split())
a,b=map(int,input().split())
h=a+b
t=[]
for i in range(n):
    x,y=map(int,input().split())
    if x<=h:
        t.append(y)
t=sorted(t)
c=0
for i in t:
    if s>=i:
        s-=i
        c+=1
    else :
        break
print(c) 