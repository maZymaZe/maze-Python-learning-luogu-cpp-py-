class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        int mid, l = 0, r = len - 1;
        while (l < r) {
            mid = (l + r) / 2;
            if ((mid == 0 || nums[mid] > nums[mid - 1]) &&
                (mid == len - 1 || nums[mid] > nums[mid + 1]))
                return mid;
            else if ((mid == 0 || nums[mid] > nums[mid - 1]) &&
                     (mid != len - 1 && nums[mid] < nums[mid + 1]))
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};