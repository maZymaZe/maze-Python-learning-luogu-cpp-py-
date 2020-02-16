s=input()
f=0
if int(s)!=0:
    if s[0]!='-':
        s=list(reversed(s))
        for i in s:
            if i!='0' or f==1:
                print(i,end='')
                f=1
    else:
        print('-',end='')
        s=list(reversed(s[1:]))
        for i in s:
            if i!='0' or f==1:
                print(i,end='')
                f=1
else:
    print(0)