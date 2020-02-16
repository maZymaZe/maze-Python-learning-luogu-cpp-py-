s=[]
v=0
for i in range(5000):
    v+=i
    s.append(v)

n=int(input())
for i in range(len(s)):
    if n>s[i] and n<=s[i+1]:
        r1=i
        r2=s[i]
        r3=s[i+1]
        break

h=i+2
if i%2==1 :
    l=n-r2
    r= h-l
else :
    r=n-r2
    l=h-r
print('%d/%d'%(l,r))

 