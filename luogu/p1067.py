n=int(input())
t=input().split()
s=[]
for i in range(n+1):
    s.append(int(t[i]))
f=-1
for i in range(1+n):
    if s[i]!=0 :
        f=i
        break
if f==-1:
    print(0)
else:
    if f<n-1:
        if s[f]*s[f]!=1:
            print("%dx^%d"%(s[f],n-f),end='')
        elif s[f]==1:
            print("x^%d"%(n-f,),end='')
        elif s[f]==-1:
            print("-x^%d"%(n-f,),end='')    
        for i in range(f+1,n-1):
            if s[i]==1:
                print("+x^%d"%(n-i,),end='')
            elif s[i]>0:
                print("+%dx^%d"%(s[i],n-i),end='')
            if s[i]==-1:
                print("-x^%d"%(n-i,),end='')
            elif s[i]<0:
                print("%dx^%d"%(s[i],n-i),end='')
        if s[n-1]>0 :
            if s[n-1]!=1:
                print("+%dx"%(s[n-1],),end='')
            else:
                print("+x",end='')
        if s[n-1]<0:
            if s[n-1]!=-1:
                print("%dx"%(s[n-1],),end='')
            else:
                print("-x",end='')
        if s[n]>0:
            print("+%d"%(s[n],),end='')
        if s[n]<0:
            print("%d"%(s[n],),end='')
    elif f==n-1:
        if s[f]==1:
            print("x",end='')
        elif s[f]==-1:
            print("-x",end='')
        else:
            print("%dx"%(s[n],),end='')
        if s[n]>0:
            print("+%d"%(s[n],),end='')
        if s[n]<0:
            print("%d"%s[n],end='')
    else :
        print(s[n])

        
        
        


       
