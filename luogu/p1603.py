t=["dgddrdf","one" ,"two" ,"three" ,"four" ,"five" ,"six","seven" ,"eight" ,"nine", "ten",\
"eleven","twelve" ,"thirteen" ,"fourteen", "fifteen" ,"sixteen"\
,"seventeen" ,"eighteen", "nineteen","twenty"]
s=input().lower().split()
n=[]
for i in s:
    if i in t:
        n.append(t.index(i)**2%100)
    else:
        if i=='a':
            n.append(1)
        if i=='both':
            n.append(4)
        if i=='another':
            n.append(1)
        if i=='first':
            n.append(1)
        if i=='second':
            n.append(4)
        if i=='third':
            n.append(9)
        


if len(n)!=0:
    n.sort()
    f=0
    for i in n:
        if i==0:
            pass
        elif i<10:
            if f==0 :
                print(i,end='')
                f=1
            else:
                f=1
                print("0",end='')
                print(i,end='')
        else:
            print(i,end='')
            f=1
    if f==0 :
        print(0)
else:
    print(0)

