class Solution {
   public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int l = floor.size();
        int dp[1002][1002] = {0};
        for (int i = 0; i < l; i++) {
            dp[0][i + 1] = dp[0][i] + (floor[i] == '1');
        }
        for (int i = 1; i <= numCarpets; i++) {
            for (int j = 1; j <= l; j++) {
                dp[i][j] = min(dp[i - 1][max(0, j - carpetLen)],
                               dp[i][j - 1] + (floor[j - 1] == '1'));
            }
        }
        return dp[numCarpets][l];
    }
};