class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int mi = 0x3f3f3f3f, l = prices.size(), ans = 0;
        for (int i = 0; i < l; i++) {
            if (prices[i] - mi > ans)
                ans = prices[i] - mi;
            if (mi > prices[i])
                mi = prices[i];
        }
        return ans;
    }
};