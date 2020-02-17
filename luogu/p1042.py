s=input()
while not("E"in s):
    s+=input()
a=0
b=0
j=11
for i in s:
    if i=="E":
        print("%d:%d"%(a,b))
        break
    elif i=="W":
        a+=1
    elif i=="L":
        b+=1
    if (a>=j or b>=j) and (a-b)**2>3:
        print("%d:%d"%(a,b))
        a=0
        b=0
print("")
a=0
b=0
j=21
for i in s:
    if i=="E":
        print("%d:%d"%(a,b))
        break
    elif i=="W":
        a+=1
    elif i=="L":
        b+=1
    if (a>=j or b>=j) and (a-b)**2>3:
        print("%d:%d"%(a,b))
        a=0
        b=0
