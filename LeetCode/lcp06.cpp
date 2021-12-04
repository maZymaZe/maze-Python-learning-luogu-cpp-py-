class Solution {
   public:
    int minCount(vector<int>& coins) {
        int ans = 0;
        for (int i : coins)
            ans += (i + 1) / 2;
        return ans;
    }
};