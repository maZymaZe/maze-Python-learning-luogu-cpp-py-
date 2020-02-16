s=input()
for i in range(len(s)):
    if s[i]=='=':
        d=i
        break
for i in range(len(s)):
    if ord(s[i])>=ord('a') and ord(s[i])<=ord('z'):
        x=s[i]
        break
rs=s[(d+1):]
ls=s[:(d)]
lx=0
lc=0
rx=0
rc=0
rs=rs+'+'
ls=ls+'+'
if rs[0]!='-':
    rs='+'+rs
if ls[0]!='-':
    ls='+'+ls
for i in range(1,len(ls)):
    if ls[i]=='+' or ls[i]=='-':
        tail=i
        break
head=0
while(tail<len(ls)):
    if ls[tail-1]==x:
        if tail-head==2:
            if ls[head]=='+':
                lx+=1
            if ls[head]=='-':
                lx-=1
        else:
            #print(ls[head+1:tail-1])
            if ls[head]=='+':
                lx+=int(ls[head+1:tail-1])
            if ls[head]=='-':
                lx-=int(ls[head+1:tail-1])
    else:
        #print(ls[head+1:tail])
        if ls[head]=='+':
            lc+=int(ls[head+1:tail])
        if ls[head]=='-':
            lc-=int(ls[head+1:tail])
    head=tail
    if tail!=len(ls)-1:
        for i in range(tail+1,len(ls)):
            if ls[i]=='+' or ls[i]=='-':
                tail=i
                break
    else :
        tail+=1
for i in range(1,len(rs)):
    if rs[i]=='+' or rs[i]=='-':
        tail=i
        break
head=0
while(tail<len(rs)):
    if rs[tail-1]==x:
        if tail-head==2:
            if rs[head]=='+':
                rx+=1
            if rs[head]=='-':
                rx-=1
        else:
            if rs[head]=='+':
                rx+=int(rs[head+1:tail-1])
            if rs[head]=='-':
                rx-=int(rs[head+1:tail-1])
    else:
        if rs[head]=='+':
            rc+=int(rs[head+1:tail])
        if rs[head]=='-':
            rc-=int(rs[head+1:tail])
    head=tail
    if tail!=len(rs)-1:
        for i in range(tail+1,len(rs)):
            if rs[i]=='+' or rs[i]=='-':
                tail=i
                break
    else :
        tail+=1

print('%c=%.3f'%(x,(lc-rc)/(rx-lx)))

            





        

