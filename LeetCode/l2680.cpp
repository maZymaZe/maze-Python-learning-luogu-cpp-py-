class Solution {
   public:
    long long maximumOr(vector<int>& nums, int k) {
        int c[100] = {0};
        long long base = 0;
        for (int i : nums) {
            int p = 0;
            base |= i;
            while (i) {
                c[p++] += i & 1;
                i >>= 1;
            }
        }
        long long ans = 0;
        for (int i : nums) {
            long long x = ((long long)i) << k, y = base;
            int p = 0;
            while (i) {
                if ((i & 1) && c[p] == 1)
                    y ^= (1 << p);
                i >>= 1;
                p++;
            }
            ans = max(ans, x | y);
        }
        return ans;
    }
};