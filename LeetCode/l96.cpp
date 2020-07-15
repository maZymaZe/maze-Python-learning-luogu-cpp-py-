class Solution {
public:
    int numTrees(int n) {
        vector<int> dp={1,1,2};
        for(int i=3;i<=n;i++){
            int t=0;
            for(int j=0;j<i;j++){
                t+=dp[j]*dp[i-1-j];
            }
            dp.push_back(t);
        }
        return dp[n];
    }
};