class Solution {
   public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = nums.size();
        int ans = l;
        auto tmp = nums;
        auto tend = unique(tmp.begin(), tmp.end());
        for (int i = 0; i < l; i++) {
            int ll = nums[i] - l + 1, lr = nums[i];
            int rl = nums[i], rr = nums[i] + l - 1;
            int ol = upper_bound(tmp.begin(), tend, lr) -
                     lower_bound(tmp.begin(), tend, ll);
            int orr = upper_bound(tmp.begin(), tend, rr) -
                      lower_bound(tmp.begin(), tend, rl);
            ans = min(ans, l - ol);
            ans = min(ans, l - orr);
        }
        return ans;
    }
};