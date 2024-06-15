class Solution {
   public:
    int maximumBeauty(vector<int>& nums, int k) {
        int mx = 1e5 + 2 * k + 10;
        vector<int> rs(mx);
        for (int i : nums) {
            rs[i]++;
            rs[i + 2 * k + 1]--;
        }
        int ans = 0, tot = 0;
        for (int i : rs) {
            tot += i;
            ans = max(ans, tot);
        }
        return ans;
    }
};