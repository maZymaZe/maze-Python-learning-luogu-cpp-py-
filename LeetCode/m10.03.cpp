class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        if (right == -1)
            return -1;
        while (left < right) {  // 循环结束条件left==right
            int mid = left + (right - left) / 2;
            if (nums[left] < nums[mid]) {  // 如果左值小于中值，说明左边区间升序
                if (nums[left] <= target &&
                    target <=
                        nums[mid]) {  // 如果目标在左边的升序区间中，右边界移动到mid
                    right = mid;
                } else {  // 否则目标在右半边，左边界移动到mid+1
                    left = mid + 1;
                }
            } else if (
                nums[left] >
                nums[mid]) {  // 如果左值大于中值，说明左边不是升序，右半边升序
                if (nums[left] <= target ||
                    target <= nums[mid]) {  // 如果目标在左边，右边界移动到mid
                    right = mid;
                } else {  // 否则目标在右半边，左边界移动到mid+1
                    left = mid + 1;
                }
            } else if (
                nums[left] ==
                nums[mid]) {  // 如果左值等于中值，可能是已经找到了目标，也可能是遇到了重复值
                if (nums[left] !=
                    target) {  // 如果左值不等于目标，说明还没找到，需要逐一清理重复值。
                    left++;
                } else {  // 如果左值等于目标，说明已经找到最左边的目标值
                    right = left;  // 将右边界移动到left，循环结束
                }
            }
        }
        return (nums[left] == target) ? left : -1;  // 返回left，或者-1
    }
};
