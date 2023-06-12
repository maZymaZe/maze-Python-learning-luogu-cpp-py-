class Solution {
   public:
    int unequalTriplets(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int fi[1001] = {0}, li[1001] = {0}, l = nums.size();
        for (int i = 0; i < l; i++) {
            if (fi[nums[i]] == 0) {
                fi[nums[i]] = i + 1;
            }
            li[nums[i]] = i + 1;
        }
        for (int i = 2; i < 1000; i++) {
            if (fi[i]) {
                ans += (li[i] - fi[i] + 1) * (fi[i] - 1) * (l - li[i]);
            }
        }
        return ans;
    }
};