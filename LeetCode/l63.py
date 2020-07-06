class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if len(obstacleGrid)==0:
            return 0
        if len(obstacleGrid[0])==0:
            return 1
        n,m=len(obstacleGrid),len(obstacleGrid[0])
        dp=[0 for _ in range(m+1)]
        for i in range(1,m+1):
            if obstacleGrid[0][i-1]==0:
                dp[i]=1
            else:
                break;
        for i in range(1,n):
            for j in range(1,m+1):
                if obstacleGrid[i][j-1]==0:
                    dp[j]+=dp[j-1]
                else :
                    dp[j]=0
        return dp[m]