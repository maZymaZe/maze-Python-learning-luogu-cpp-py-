class Solution {
   public:
    long long MOD;
    vector<long long> dp;
    long long qpow(long long a, long long b) {
        if (b == 0)
            return 1;
        if (!a)
            return 0;
        long long ans = 1;
        while (b) {
            if (b & 1) {
                ans = ans * a % MOD;
            }
            b >>= 1;
            a = a * a % MOD;
        }
        return ans;
    }
    long long cal1(long long x) {
        vector<int> v(70);
        dump(x, v);
        long long ans = 0;
        for (int i = 64; i >= 1; i--) {
            if (v[i]) {
                ans += dp[i - 1];
                ans += (x - (1ll << (i - 1)) + 1);
                x -= (1ll << (i - 1));
            }
        }
        return ans;
    }
    void cal2(long long x, vector<long long>& v) {
        vector<int> v2(70);
        fill(v.begin(), v.end(), 0);
        dump(x, v2);
        for (int i = 64; i > 0; i--) {
            if (v2[i]) {
                for (int j = i - 1; j > 0; j--) {
                    // i>2
                    v[j] += (1ll << (i - 2));
                }
                v[i] += (x - (1ll << (i - 1)) + 1);
                x -= (1ll << (i - 1));
            }
        }
    }
    void dump(long long x, vector<int>& v) {
        fill(v.begin(), v.end(), 0);
        int p = 0;
        while (x) {
            v[++p] = (x & 1);
            x >>= 1;
        }
    }

    vector<int> findProductsOfElements(vector<vector<long long>>& queries) {
        dp.resize(70);
        for (int i = 1; i <= 55; i++) {
            dp[i] = (1ll << (i - 1)) * i;
        }

        int len = queries.size();
        vector<int> v1(70);
        vector<long long> vl1(70), vl2(70);
        vector<int> ans(len);
        for (int i = 0; i < len; i++) {
            long long a = queries[i][0], b = queries[i][1];
            a++, b++;
            MOD = queries[i][2];
            long long l, r, mid, s, t;
            l = 1, r = 1e14;
            while (l < r) {
                mid = (l + r + 1) / 2;
                if (cal1(mid) <= b) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            s = l;
            l = 1, r = 1e14;
            while (l < r) {
                mid = (l + r) / 2;
                if (cal1(mid) >= a) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            t = l;
            long long tans = 1;

            if (t > s) {
                long long cnt = cal1(s);
                dump(t, v1);
                for (int j = 1; j <= 64; j++) {
                    if (v1[j]) {
                        cnt++;
                        if (cnt >= a && cnt <= b) {
                            tans = tans * (1 << (j - 1)) % MOD;
                        }
                    }
                }
                ans[i] = tans;
            } else {
                int c1 = cal1(t) - a + 1, c2 = b - cal1(s);
                if (c1) {
                    dump(t, v1);
                    for (int j = 64; j >= 1 && c1; j--) {
                        if (v1[j]) {
                            tans = tans * ((1ll << (j - 1)) % MOD) % MOD;
                            c1--;
                        }
                    }
                }
                if (c2) {
                    dump(s + 1, v1);
                    for (int j = 1; j <= 64 && c2; j++) {
                        if (v1[j]) {
                            tans = tans * ((1ll << (j - 1)) % MOD) % MOD;
                            c2--;
                        }
                    }
                }
                if (s >= t) {
                    cal2(s, vl1), cal2(t, vl2);
                    for (int j = 64; j > 1; j--) {
                        long long y = vl1[j] - vl2[j],
                                  x = (1ll << (j - 1)) % MOD;
                        tans = tans * qpow(x, y);
                        tans %= MOD;
                    }
                }
                ans[i] = tans;
            }
        }
        return ans;
    }
};