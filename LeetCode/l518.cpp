class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount+10);
        dp[0] =1;
        int l=coins.size();
        for(int i=0; i<l; i++){
            for(int j=coins[i]; j<=amount;j++){
                dp[j]+=dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};