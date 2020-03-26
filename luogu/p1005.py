n,m=map(int,input().split())
ans=0
for iii in range(n):
    ss=input().split()
    tt=[]
    tt.append(0)
    for ii in range(m):
        tt.append(int(ss[ii]))
    dp=[[0 for i in range(m+2)]for j in range(m+2)]
    for i in range(1,m+1):
        for j in range(1,i+2):           
            if j==1 :
                dp[i][j]=dp[i-1][j]+(2**i)*tt[m-i+j]
            elif j==i+1:
                dp[i][j]=dp[i-1][j-1]+(2**i)*tt[j-1]
            else : 
                dp[i][j]=max(dp[i-1][j-1]+(2**i)*tt[j-1],dp[i-1][j]+(2**i)*tt[m-i+j])
    mx=0
    for i in range(1,m+2):
        mx=max(mx,dp[m][i])
    ans+=mx
print(ans)