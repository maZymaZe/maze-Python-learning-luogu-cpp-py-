t=[]
for i in range(300):
    t.append(" ")
a=input()
b=input()
c=input()
f=0
for i in range(len(a)):
    if t[ord(a[i])]==b[i]:
        pass
    elif t[ord(a[i])]==' ' and not(b[i] in t):
        t[ord(a[i])]=b[i]
    else:
        f=1
        break
for i in range(ord("A"),ord("Z")+1):
    if t[i]==' ':
        f=1
        break
if f==1:
    print("Failed")
else:
    for i in c:
        print(t[ord(i)],end='')

