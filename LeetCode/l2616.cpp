class Solution {
   public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.back() - nums.front(), mid, len = nums.size();
        while (l < r) {
            mid = (l + r) / 2;
            int p1 = 0, p2 = 0, p3;
            for (int i = 1; i < len; i++) {
                p3 = p2;
                if (nums[i] - nums[i - 1] <= mid)
                    p3 = max(p3, p1 + 1);
                p1 = p2;
                p2 = p3;
            }
            if (p2 >= p) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
};