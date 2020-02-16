r=[]
for h in range(21):
    t=[]
    for i in range(21):
        s=[]
        for j in range(21):
            s.append(-1)
        t.append(s)
    r.append(t)

def fr(h,i,j):
    if h<=0 or i<=0 or j<=0:
        return 1
    elif h>20 or i>20 or j>20:
        return fr(20,20,20)
    elif r[h][i][j]!=-1:
        return r[h][i][j]
    elif h<i and i<j :
        return  fr(h,i,j-1)+fr(h,i-1,j-1)-fr(h,i-1,j)
    else:
        return  fr(h-1,i,j)+fr(h-1,i-1,j)+fr(h-1,i,j-1)-fr(h-1,i-1,j-1)

for h in range(21):
    for i in range(21):
        for j in range(21):
            if r[h][i][j]==-1:
                r[h][i][j]=fr(h,i,j)

a,b,c=map(int,input().split())
while a!=-1 or b!=-1 or c!=-1:
    print('w(%d, %d, %d) = %d'%(a,b,c,fr(a,b,c)))
    a,b,c=map(int,input().split())
