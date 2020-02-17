nn=int(input())
for ii in range(nn):
    aa=input().split()
    n=int(aa[0])
    s=aa[1]
    if s[2]=='1':
        ans=0
    else:
        ans=int(s[4:len(s)-1])
    xx=[]
    nu=[]
    yx=[]
    err=0
    c=0
    mx=0
    for jj in range(n):
        t=input().split()
        if t[0]=='F':
            if t[1] in xx or t[1] in nu:
                err=1
            else:
                if t[2]=='n' and t[3]=='n':
                    if len(nu)==0:
                        xx.append(t[1])
                    else:
                        nu.append(t[1])
                elif t[2]=='n' :
                    nu.append(t[1])
                elif t[3]=='n':
                    if len(nu)==0:
                        xx.append(t[1])
                        yx.append(t[1])
                    else:
                        nu.append(t[1])
                elif int(t[2])>int(t[3]):
                    nu.append(t[1])
                else:
                    if len(nu)==0:
                        xx.append(t[1])
                    else:
                        nu.append(t[1])
        else:
            if len(nu)==0 and len(xx)==0:
                err=1
            elif len(nu)!=0:
                nu.pop(len(nu)-1)
            else:
                if xx[len(xx)-1] in yx:
                    yx.pop(len(yx)-1)
                xx.pop(len(xx)-1)
        mx=max(mx,len(yx))
    if len(xx)!=0 or len(nu)!=0:
        err=1
    if err==1:
        print("ERR")
    elif ans==mx:
        print("Yes")
    else:
        print("No")



                    

                


