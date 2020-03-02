a=input()
l=0
e=0
for i in a:
    if i=='(':
        l+=1
    if i==')':
        l-=1
    if l<0:
        e=1
if l==0 and e==0:
    print("YES")
else:
    print("NO")