class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int l = nums.size();
        if (l < 4)
            return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < l - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            if (0ll+nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            if (0ll+nums[i] + nums[l - 1] + nums[l - 2] + nums[l - 3] < target)
                continue;
            for (int j = i + 1; j < l - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                if (0ll+nums[j] + nums[j + 1] + nums[j + 2] + nums[i] > target)
                    break;
                if (0ll+nums[j] + nums[i] + nums[l - 1] + nums[l - 2] < target)
                    continue;
                int left = j + 1, right = l - 1;
                while (left < right) {
                    int s = 0ll+nums[i] + nums[j] + nums[left] + nums[right];
                    if (s == target) {
                        ans.push_back(
                            {nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        left++;
                        while (right > left && nums[right] == nums[right - 1])
                            right--;
                        right--;
                    } else if (s > target)
                        right--;
                    else
                        left++;
                }
            }
        }
        return ans;
    }
};