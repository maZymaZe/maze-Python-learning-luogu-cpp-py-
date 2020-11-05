public class Solution
{
    public int NumRollsToTarget(int d, int f, int target)
    {
        int[] dp = new int[30005];
        const int mod = 1000000007;
        dp[0] = 1;
        for (int i = 1; i <= d; i++)
        {
            for (int j = i * f; j >= i; j--)
            {
                dp[j] = 0;
                for (int k = 1; k <= f; k++)
                {
                    if (j - k >= i - 1)
                    {
                        dp[j] = (dp[j] + dp[j - k]) % mod;
                    }
                }
            }
        }
        return dp[target];
    }
}