class Solution {
   public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid;
        if (r == 0)
            return nums[0];
        while (l < r) {
            mid = l + ((r - l) >> 1);
            if (nums[mid] == nums[mid - 1]) {
                if ((mid - l + 1) % 2)
                    r = mid;
                else
                    l = mid + 1;
            } else if (nums[mid] == nums[mid + 1]) {
                if ((mid - l) % 2)
                    r = mid - 1;
                else
                    l = mid;
            } else
                return nums[mid];
        }
        return nums[l];
    }
};