class Solution {
   public:
    int minCapability(vector<int>& nums, int k) {
        int l = 0, r = 1e9 + 7, mid;
        while (l < r) {
            mid = (l + r) / 2;
            int p = 0, len = nums.size(), cnt = 0;
            while (p < len) {
                if (nums[p] <= mid)
                    cnt++, p++;
                p++;
            }
            if (cnt >= k)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};