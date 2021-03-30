class Solution {
   public:
    bool ck(vector<int>& nums, int m, int n) {
        long long c = 0;
        for (int i : nums)
            c += (i - 1) / m;
        return c <= n;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = 1e9;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (ck(nums, mid, maxOperations)) {
                r = mid;
            }
            else l = mid + 1;
        }
        return r;
    }
};