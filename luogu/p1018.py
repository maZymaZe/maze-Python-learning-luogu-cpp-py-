n,k= map(int, input().split())
s= input()
dp=[[0 for i in range(10)] for j in range(50)]
for i in range(n):
    dp[i][0]=int(s[0:i+1])
for i in range(1,k+1):
    for j in range(i,n):
        for l in range(i-1,j):
            dp[j][i]=max(dp[j][i],dp[l][i-1]*(int(s[l+1:j+1])))
print(dp[n-1][k])