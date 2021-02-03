class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int l=stones.size();
        if(l==1)return stones[0];
        int s=0;
        for(int i=0; i<l; i++)s+=stones[i];
        vector<int> dp(s/2+1);
        for(int i=0;i<l;i++){
            for(int j=s/2;j>=stones[i];j--){
                dp[j]=max(dp[j],dp[j-stones[i]]+stones[i]);
            }
        } 
        return s-2*dp[s/2];
    }
};