class Solution {
   public:
    int ps[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int ck(int x, int y) {
        int t = 0;
        for (int i = 0; i < 10; i++) {
            if ((1 << i) & x)
                t = i;
        }
        if (y % ps[t])
            return -1;
        for (int i = 0; i < 10; i++) {
            if (y % ps[i] == 0) {
                y /= ps[i];
                if (y % ps[i] == 0)
                    return -1;
                if (!((1 << i) & x))
                    return -1;
                x ^= (1 << i);
            }
        }
        return x;
    }
    long long qpow(int x) {
        long long ret = 1, a = 2, MOD = 1e9 + 7;
        while (x) {
            if (x & 1)
                ret = ret * a % MOD;
            x >>= 1;
            a = a * a % MOD;
        }
        return ret;
    }
    int numberOfGoodSubsets(vector<int>& nums) {
        long long cnt[40] = {0};
        for (int i : nums)
            cnt[i]++;
        const int mx = (1 << 10);
        long long ans[mx] = {0}, MOD = 1e9 + 7;
        ans[0] = 1;
        for (int i = 0; i < mx; i++) {
            for (int j = 2; j <= 30; j++) {
                int ch = ck(i, j);
                if (ch >= 0)
                    ans[i] = (ans[i] + ans[ch] * cnt[j] % MOD) % MOD;
            }
        }
        long long ret = 0;
        for (int i = 1; i < mx; i++) {
            ret = (ret + ans[i]) % MOD;
        }
        ret = ret * qpow(cnt[1]) % MOD;
        return ret;
    }
};