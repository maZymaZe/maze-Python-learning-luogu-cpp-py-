x,n=map(int,input().split())
c=n+x-1
s=0
s+=c//7*5*250
l=c%7
if l<=5 :
    s+=l*250
else :
    s+=1250
if x<=5 :
    s-=(x-1)*250
else :
    s-=1250
print(s)