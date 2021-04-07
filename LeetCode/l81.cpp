class Solution {
   public:
    bool mysearch(vector<int>& nums, int l, int r, int target) {
        int mid = (l + r) / 2;
        if (l + 1 >= r) {
            return nums[l] == target || nums[r] == target;
        }
        if (target == nums[l] || target == nums[r])
            return true;
        if (target == nums[mid])
            return true;
        if (nums[mid] == nums[l] || nums[mid] == nums[r]) {
            return mysearch(nums, l, mid, target) ||
                   mysearch(nums, mid, r, target);
        }
        if (nums[mid] > nums[l]) {
            if (nums[mid] > target && nums[l] < target) {
                return *lower_bound(nums.begin() + l, nums.begin() + mid,
                                    target) == target;
            }
            if ((nums[mid] < target) || (nums[r] > target)) {
                return mysearch(nums, mid, r, target);
            }
            if (nums[l] > target && nums[r] < target)
                return false;
        }
        if (nums[mid] < nums[l]) {
            if (nums[mid] < target && nums[r] > target) {
                return *lower_bound(nums.begin() + mid, nums.begin() + r,
                                    target) == target;
            }
            if ((nums[mid] > target) || (nums[l] < target)) {
                return mysearch(nums, l, mid, target);
            }
            if (nums[l] > target && nums[r] < target)
                return false;
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        return mysearch(nums, 0, nums.size() - 1, target);
    }
};