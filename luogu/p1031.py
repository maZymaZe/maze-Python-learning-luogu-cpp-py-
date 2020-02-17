n=int(input())
t=input().split()
s=[]
h=0
for i in t:
    s.append(int(i))
    h+=int(i)
h//=n
c=0
for i in range(n-1):
    if s[i]!=h:
        s[i+1]-=h-s[i]
        c+=1
print(c)

