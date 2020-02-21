n=int(input())
lie=[]
ans=[] 
for i in range(n+1):
    lie.append(0)
    ans.append(0)
zx=[]
yx=[]
for i in range(61):
    zx.append(0)
    yx.append(0)
c=0
def dfs(t):
    global n,c,ans,zx,yx,lie
    if t==n+1:
        c+=1
        if c<=3:
            for i in range(1,n+1):
                print(ans[i],end=' ')
            print("")
    else:
        for i in range(1,n+1):
            if lie[i]==0 and zx[t+i]==0 and yx[t-i+30]==0:
                lie[i]=1 
                zx[t+i]=1
                yx[t-i+30]=1
                ans[t]=i
                dfs(t+1)
                lie[i]=0 
                zx[t+i]=0
                yx[t-i+30]=0
                ans[t]=0
dfs(1)
print(c)

