t=[]
c=0
for i in range(20003):
    t.append(0)
n=int(input())
s=input().split()
for i in range(n):
    for j in range(i):
        if int(s[i])!=0 and int(s[j])!=0:
            t[int(s[i])+int(s[j])]+=1
for i in range(n):
    if t[int(s[i])]!=0 :
        c+=1
print(c)