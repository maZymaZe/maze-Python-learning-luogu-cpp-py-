class Solution {
   public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0, l = nums.size();
        for (int i = 0; i < l - 2; i++) {
            ans += tsm(nums, i + 1, target - nums[i]);
        }
        return ans;
    }
    int tsm(vector<int>& nums, int si, int target) {
        int ans = 0, l = nums.size(), lf = si, ri = nums.size() - 1;
        while (lf < ri) {
            if (nums[lf] + nums[ri] < target) {
                ans += ri - lf;
                lf++;
            } else
                ri--;
        }
        return ans;
    }
};