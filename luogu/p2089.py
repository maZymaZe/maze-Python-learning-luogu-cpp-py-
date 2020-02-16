t=[]
for i in range(10):
    t.append(i)
c=0
def dfs1(m,l):
    global c
    global t
    if m==10:
        if l==0:
            c+=1
    else:
        for i in range(1,4):
            if l>=i :
                t[m]=i
                dfs1(m+1,l-i)
def dfs2(m,l):
    global t
    if m==10:
        if l==0:
            for i in t:
                print(i,end=' ')    
            print('')
    else:
        for i in range(1,4):
            if l>=i :
                t[m]=i
                dfs2(m+1,l-i)
n=int(input())
if n<10 or n>30:
    print(0)
else:
    dfs1(0,n)
    print(c)
    dfs2(0,n)