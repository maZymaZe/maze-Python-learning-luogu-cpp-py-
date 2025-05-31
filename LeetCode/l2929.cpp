class Solution {
   public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        int mx = min(n, limit);
        for (int i = 0; i <= mx; i++) {
            int res = n - i;
            if (res < limit)
                ans += res + 1;
            else if (res <= 2 * limit) {
                ans += 2 * limit - res + 1;
            }
        }
        return ans;
    }
};