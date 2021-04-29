class Solution {
   public:
    int dp[2004][2004]={0};
    bool canCross(vector<int>& stones) {
        int l = stones.size();
        
        unordered_map<int, int> mp;
        for (int i = 0; i < l; i++) {
            mp[stones[i]] = i;
        }
        if(stones[0]!=0||stones[1]!=1)return 0;
        if(l==2)return true;
        dp[1][1] = 1;
        for (int i = 2; i < l; i++) {
            for (int j = 1; j <= l; j++) {
                /*if (mp.count(stones[i] - (j + 1))) {
                    if (j + 2 >= 1 && j + 2 <= l)
                        dp[i][j] |= dp[mp[stones[i] - (j + 1)]][j + 2];
                    if (j + 1 >= 1 && j + 1 <= l)
                        dp[i][j] |= dp[mp[stones[i] - (j + 1)]][j + 1];
                    if (j >= 1 && j <= l)
                        dp[i][j] |= dp[mp[stones[i] - (j + 1)]][j];
                }*/
                if (mp.count(stones[i] - (j))) {
                    int t=mp[stones[i] - j];
                    if (j - 1 >= 1 && j - 1 <= l)
                        dp[i][j] |= dp[t][j - 1];
                    if (j + 1 >= 1 && j + 1 <= l)
                        dp[i][j] |= dp[t][j + 1];
                    if (j >= 1 && j <= l)
                        dp[i][j] |= dp[t][j];
                }
                /*
                if (mp.count(stones[i] - (j - 1)) && j != 1) {
                    if (j - 1 >= 1 && j - 1 <= l)
                        dp[i][j] |= dp[mp[stones[i] - j + 1]][j - 1];
                    if (j - 2 >= 1 && j - 2 <= l)
                        dp[i][j] |= dp[mp[stones[i] - j + 1]][j - 2];
                    if (j >= 1 && j <= l)
                        dp[i][j] |= dp[mp[stones[i] - j + 1]][j];
                }*/
                if (i == l - 1 && dp[i][j])
                    return true;
            }
        }
        return false;
    }
};