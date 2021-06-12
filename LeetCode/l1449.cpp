class Solution {
   public:
    string largestNumber(vector<int>& cost, int target) {
        for (int i = 0; i < 9; i++) {
            for (int j = i + 1; j <= 9; j++) {
                if (cost[i] == cost[j]) {
                    cost[i] = 10000;
                    break;
                }
            }
        }
        int dp[10][5005] = {0};
        for(int i=0;i<=9;i++){
            for(int j=1;j<=5002;j++)dp[i][j] =-0x3f3f3f3f;
        }
        dp[0][0] = 0;
        for (int i = 1; i <= 9; i++) {
            for (int j = 0; j <= target; j++) {
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
                if(j-cost[i-1]>=0)dp[i][j] = max(dp[i][j], dp[i][j - cost[i - 1]] + 1);
            }
        }
        if (dp[9][target] <= 0)
            return "0";
        string ans;
        int tot = target;
        for (int i = 9; i > 0; i--) {
            int lim=tot/cost[i-1];
            for (int j = lim; j >= 0; j--) {
                if (dp[i][tot] == dp[i - 1][tot - j * cost[i - 1]] + j) {
                    ans+=string(j,i+'0');
                    tot-=j*cost[i - 1];
                    break;
                }
            }
        }
        return ans;
    }
};