class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n, dp[30][30] = {0}, sum[30][30] = {0},a[30]={0};
        n=nums.size();
    for (int i = 1; i <= n; i++)
        {
            a[i]=nums[i-1];
            sum[1][i] = sum[1][i - 1] + a[i];
            dp[i][i] = sum[i][i] = a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                sum[i][j] = sum[i][j - 1] + a[j];
            }
        }
        for (int i = n; i >= 1; i--)
        {
            for (int j = i; j <= n; j++)
            {
                dp[i][j] = sum[i][j] - min(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        if(dp[1][n]>= sum[1][n] - dp[1][n])return true;
        else return false;
    }
};