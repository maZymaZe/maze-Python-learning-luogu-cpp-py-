def dod(n):
    return n%2==1
#print(list(filter(dod,[1,2,4,5,6,9,10,15])))
l=list(range(2,10001))
i=2
s=1
def dh(n):
    if n%l[s]==0 and n//l[s]!=1 :
        return False
    else :
        return True

while i<1001 :
    l=list(filter(dh,l))
    s+=1
    i=l[s]
print(l)