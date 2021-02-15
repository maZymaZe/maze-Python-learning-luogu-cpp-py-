class Solution {
   public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int l = arr.size(),ans=0;
        sort(arr.begin(), arr.end());
        vector<long long> dp(l);
        unordered_map<int, int> mp;
        for (int i = 0; i < l; i++)
            mp.insert({arr[i], i});
        for (int i = 0; i < l; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if ((long long)arr[j] * arr[j] > (long long)arr[i])
                    break;
                else if (arr[j] * arr[j] == arr[i])dp[i] =(dp[i]+dp[j]*dp[j])%MOD;
                else if(arr[i]%arr[j]==0&&mp.count(arr[i]/arr[j])){
                    int k=mp[arr[i]/arr[j]];
                    dp[i] =(dp[i]+dp[j]*dp[k]*2)%MOD;
                }
            }
            ans=(ans+dp[i])%MOD;
        }
        return ans;
    }
};