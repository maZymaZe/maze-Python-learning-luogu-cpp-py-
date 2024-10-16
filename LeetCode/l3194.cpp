class Solution {
   public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = nums.size();
        int ma = nums[0] + nums[l - 1];
        for (int i = 0; i < l / 2; i++) {
            ma = min(ma, nums[i] + nums[l - i - 1]);
        }
        return 1.0 * ma / 2;
    }
};