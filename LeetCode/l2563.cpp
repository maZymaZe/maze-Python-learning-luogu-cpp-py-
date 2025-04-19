class Solution {
   public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int n = nums.size();
        int p = n - 1;
        for (int i = 0; i < n; i++) {
            while (p >= 0 && nums[i] + nums[p] > upper) {
                p--;
            }
            ans += p + 1 - (i <= p);
        }
        p = n - 1;
        for (int i = 0; i < n; i++) {
            while (p >= 0 && nums[i] + nums[p] >= lower) {
                p--;
            }
            ans -= p + 1 - (i <= p);
        }
        return ans / 2;
    }
};