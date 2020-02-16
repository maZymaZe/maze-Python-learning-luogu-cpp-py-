n=int(input())
t=[]
s=input().split()
for i in range(n):
    t.append(int(s[i]))
c=1
mc=0
for i in range(1,n):
    if t[i]<=t[i-1]:
        c=1
    else :
        c+=1
        if c>mc:
            mc=c
print(mc)
