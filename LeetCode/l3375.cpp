class Solution {
   public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l = nums.size();
        if (k > nums[0])
            return -1;
        int ans = 0, cur = k;
        for (int i = 0; i < l; i++) {
            if (nums[i] > cur) {
                cur = nums[i];
                ans++;
            }
        }
        return ans;
    }
};