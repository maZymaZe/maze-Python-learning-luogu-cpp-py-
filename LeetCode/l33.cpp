class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int len = nums.size(), f = 0, t = 0;
        if (target == nums[0])
            return 0;
        else if (target > nums[0])
            f = 1;
       
        int l = 0, r = len - 1, mid;
        while (l + 1 < r) {
            t = 1;
            mid = l + ((r - l) >> 1);
            if (nums[mid] > nums[l])
                l = mid;
            else
                r = mid;
        }
        int ll = 0, rr = l;
        if (f == 0) {
            ll = r, rr = len - 1;
        }
        if (t == 0||nums[l]<nums[r]) {
            ll = 0, rr = len - 1;
            if(len>1&&nums[1]== target)return 1;
        }


        while (ll < rr) {
            mid = ll + ((rr - ll) >> 1);
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                rr = mid - 1;
            else
                ll = mid + 1;
        }
        if (ll < len && ll >= 0 && nums[ll] == target)
            return ll;
        if (rr < len && rr >= 0 && nums[rr] == target)
            return rr;

        return -1;
    }
};