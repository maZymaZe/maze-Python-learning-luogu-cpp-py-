class Solution {
   public:
    int c[40] = {0};
    int val = 0;
    void add(int x) {
        int p = 0;
        while (x) {
            if (x % 2) {
                c[p]++;
                if (c[p] == 1)
                    val += (1 << p);
            }
            p++;
            x /= 2;
        }
    }
    void del(int x) {
        int p = 0;
        while (x) {
            if (x % 2) {
                c[p]--;
                if (c[p] == 0)
                    val -= (1 << p);
            }
            p++;
            x /= 2;
        }
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int l = nums.size(), t = 0;
        int ans = l + 1;
        for (int i = 0; i < l; i++) {
            add(nums[i]);
            while (t <= i && val >= k) {
                ans = min(ans, i - t + 1);
                del(nums[t]);
                t++;
            }
        }
        return ans > l ? -1 : ans;
    }
};