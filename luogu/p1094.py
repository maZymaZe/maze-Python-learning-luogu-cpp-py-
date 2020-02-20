w=int(input())
n=int(input())
t=[]
c=0

for i in range(n):
    q=int(input())
    t.append(q)
t.sort()
i=0
j=n-1
while i<=j:
    if i<j and t[i]+t[j]<=w:
        i+=1
        j-=1
        c+=1
    elif i<j and t[i]+t[j]>w:
        j-=1
        c+=1
    elif i==j and t[i]<=w:
        c+=1
        break
print(c)