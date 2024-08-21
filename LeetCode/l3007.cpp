class Solution {
   public:
    long long K;
    int X;
    long long dp[60] = {0};
    int vis[60] = {0};
    long long fd(int z) {
        if (z == 0) {
            return 0;
        }
        if (z == 1) {
            if (X == 1)
                return 1;
            return 0;
        }
        if (vis[z])
            return dp[z];
        vis[z] = 1;
        long long ans = 0;
        if (z % X == 0) {
            ans += (1ll << (z - 1));
        }
        ans += 2 * fd(z - 1);
        ans = min(ans, K + 1);
        return dp[z] = ans;
    }
    bool checkLess(long long y) {
        int c[70] = {0}, p = 0;
        long long yy = y, zz = 0;
        while (y) {
            p++;
            c[p] = y % 2;
            y /= 2;
        }
        long long tot = 0;
        for (int i = p; i >= 1; i--) {
            if (c[i]) {
                tot += fd(i - 1);
                if (tot > K)
                    return false;
                if (i % X == 0) {
                    tot += yy - (1ll << (i - 1)) + 1;
                    if (tot > K)
                        return false;
                }
                yy -= (1ll << (i - 1));
            }
        }
        return true;
    }
    long long findMaximumNumber(long long k, int x) {
        K = k, X = x;

        long long l = 1, r = 1e15, mid;
        while (l < r) {
            mid = (l + r + 1) / 2;
            if (checkLess(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};