n=int(input())
a=[]
b=[]
g=[]
k=[]
for i in range(n):
    ta,tb,tg,tk=map(int,input().split())
    a.append(ta)
    b.append(tb)
    g.append(tg)
    k.append(tk)
x,y=map(int,input().split())
r=-1
for i in range(n):
    if x>=a[i] and x<=a[i]+g[i] and y>=b[i] and y<=b[i]+k[i]:
        r=i+1
print(r)

