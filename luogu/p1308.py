a=input().upper()
f=-1
c=0
b=input().upper()
l=b.split()
f=' {} '.format(b).find(' {} '.format(a))
for i in l:
    if i==a:
        c+=1
        
if f==-1:
    print(-1)
else:
    print(c,f)