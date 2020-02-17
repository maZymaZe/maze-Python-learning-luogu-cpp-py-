p1,p2,p3=map(int,input().split())
s=input()
i=0
def p(a,b,r):
    global p1,p2,p3,s
    if ord(b)-ord(a)==1:
        t=a+b
    if ord(b)-ord(a)<1:
        t=a+'-'+b   
    else :
        t=a
        for i in range(ord(a)+1,ord(b)):
            if p1==1:
                t+=p2*chr(i)

            if p1==2 :
                if ord(a)>60:
                    t+=p2*chr(i).upper()
                else:
                    t+=p2*chr(i)
            if p1==3 :
                t+=p2*"*"
        t+=b
        if p3==2:
            t=t[::-1]
            t=t[len(t)-1]+t[1:len(t)-1]+t[0]
    
    if  r+2<len(s) and s[r+2]=='-' :
        print(t[0:len(t)-1],end='')
    else:
        print(t,end='')            
ll=0
for i in range(len(s)):
    if ord(s[i])==ord('-') and i>0 and i<len(s)-1 and s[i-1]!='-'and s[i+1]!='-' :
        if (ord(s[i-1])-60)*(ord(s[i+1])-60)>0:           
            if ll<i-1:
                print(s[ll:i-1],end='')
            p(s[i-1],s[i+1],i)
            t=i+2
            while t<len(s)and s[t]=='-':
                t+=2
            ll=t
        else:
            if ll<i-1:
                print(s[ll:i-1],end='')
            if i+2<len(s) and s[i+2]=='-':
                print(s[i-1:i+1],end="")
            else:
                print(s[i-1:i+2],end="")
            t=i+2
            while t<len(s)and s[t]=='-':
                t+=2
            ll=t
if ll<len(s):
    print(s[ll:len(s)],end='')    