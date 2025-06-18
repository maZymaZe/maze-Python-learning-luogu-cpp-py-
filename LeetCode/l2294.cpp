class Solution {
   public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mi = nums[0], ans = 1, l = nums.size();
        for (int i = 1; i < l; i++) {
            if (nums[i] - mi > k) {
                ans++;
                mi = nums[i];
            }
        }
        return ans;
    }
};