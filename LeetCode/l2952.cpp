class Solution {
   public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int ans = 0, x = 1, l = coins.size(), i = 0;
        while (x <= target) {
            if (i < l && coins[i] <= x) {
                x += coins[i];
                i++;
            } else {
                x *= 2;
                ans++;
            }
        }
        return ans;
    }
};