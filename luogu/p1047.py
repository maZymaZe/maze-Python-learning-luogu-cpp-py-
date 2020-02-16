l,m=map(int,input().split())
t=[]
for i in range(l+3):
    t.append(0)
for i in range(m):
    x,y=map(int,input().split())
    t[x]-=1
    t[y+1]+=1
s=0
n=0
for i in range(0,l+1):
    n+=t[i]
    if n>=0 :
        s+=1
    if i==150:
        pass

print(s)