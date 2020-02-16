a,b,c,d=map(int,input().split())
e=d-b
if e<0 :
    e+=60
    f=c-a-1
else :
    f=c-a
print(f,e)