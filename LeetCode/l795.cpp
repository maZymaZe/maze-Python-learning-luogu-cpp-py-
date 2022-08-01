class Solution {
   public:
    long long ans = 0;
    int l, u, v;
    void f(vector<int>& nums, int x, int y) {
        if (x >= y)
            return;
        long long tot = 0, le = y - x, c = 0;
        for (int i = x + 1; i <= y; i++) {
            if (nums[i] < u) {
                c++;
            } else {
                tot += (c + 1) * c / 2;
                c = 0;
            }
        }
        tot += (c + 1) * c / 2;
        ans += (le + 1) * le / 2 - tot;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int pre = -1;
        l = nums.size(), u = left, v = right;
        for (int i = 0; i < l; i++) {
            if (nums[i] > right) {
                f(nums, pre, i - 1);
                pre = i;
            }
        }
        f(nums, pre, l - 1);
        return ans;
    }
};
