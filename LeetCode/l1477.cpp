class Solution {
   public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int l = 0;
        int sz = arr.size();
        vector<int> dp(sz);
        const int INF = 0x3f3f3f3f;
        int tm = INF, res = INF;
        int ts = 0;
        for (int i = 0; i < sz; i++) {
            ts += arr[i];
            while (ts > target)
                ts -= arr[l], l++;
            if (ts == target) {
                tm = min(tm, i - l + 1);
                if(l)res=min(res,i-l+1+dp[l-1]);
            }
            dp[i]=tm;
        }
        return res<INF?res:-1;
    }
};