class Solution {
   public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int c[201] = {0};
        for (int i : nums)
            c[i]++;
        int ans = 0;
        for (int i = diff; i + diff <= 200; i++) {
            if (c[i] && c[i - diff] && c[i + diff])
                ans++;
        }
        return ans;
    }
};