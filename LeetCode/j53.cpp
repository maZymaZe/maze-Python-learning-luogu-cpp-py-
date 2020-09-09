class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (!len)
            return 0;
        if (nums[0] > target || nums[len - 1] < target)
            return 0;
        int l = 0, r = len - 1, mid, lb, ub;
        if (nums[0] == target)
            lb = 0;
        else {
            while (l < r - 1) {
                int mid = l + ((r - l) >> 1);
                if (nums[mid] >= target)
                    r = mid;
                else
                    l = mid;
            }
            lb = r;
        }
        l = 0, r = len - 1;
        if (nums[len - 1] == target)
            ub = len - 1;
        else{
            while (l < r - 1) {
                int mid = l + ((r - l) >> 1);
                if (nums[mid] > target)
                    r = mid;
                else
                    l = mid;
            }
            ub = l;
        }
        if (ub >= lb)
            return ub-lb+1;
        return 0;
    }
};