f=0
w=-1
n=input()
for i in range(len(n)):
    if n[i]=='.':
        w=i
        f=1
        break
    if n[i]=='/':
        w=i
        f=2
        break
    if n[i]=='%':
        w=i
        f=3
        break
ff=0
if f==0:
    if int(n)==0:
        print('0',end='')
    else:
        for i in range(len(n)):
            if ff==0 and n[len(n)-i-1]=='0':
                pass
            else:
                print(n[len(n)-i-1],end='')
                ff=1
if f==1:
    if int(n[:w])==0:
        print('0',end='')
    else :
        for i in range(w):
            if ff==0 and n[w-i-1]=='0':
                pass
            else:
                print(n[w-i-1],end='')
                ff=1
        ff=0
    print('.',end='')
    if int(n[w+1:])==0:
        print('0',end='')
    else:
        for i in range(w+1,len(n)):
            if ff==0 and n[i]=='0':
                pass
            else:
                r=i
                break
        for i in range(len(n)-r):
            print(n[len(n)-i-1],end='')
if f==2:
    if int(n[:w])==0:
        print('0',end='')
    else:
        for i in range(w):
            if ff==0 and n[w-i-1]=='0':
                pass
            else:
                print(n[w-i-1],end='')
                ff=1
    ff=0
    print('/',end='')
    for i in range(len(n)-w-1):
        if ff==0 and n[len(n)-i-1]=='0':
            pass
        else:
            print(n[len(n)-i-1],end='')
            ff=1
if f==3:
    if len(n)==2 and n[0]=='0':
        print('0%',end='')
    else :
        for i in range(len(n)-1):
            if ff==0 and n[len(n)-1-i-1]=='0':
                pass
            else:
                print(n[len(n)-1-i-1],end='')
                ff=1
        print('%',end='')

