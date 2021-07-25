class Solution {
   public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int tot = 0, l = coins.size();
        for (int i = 0; i < l; i++) {
            if (coins[i] > tot + 1)
                break;
            tot += coins[i];
        }
        return tot + 1;
    }
};