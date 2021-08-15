class Solution {
   public:
    int countArrangement(int n) {
        vector<int> f(1 << n);
        f[0] = 1;
        for (int mk = 1; mk < (1 << n); mk++) {
            int num = __builtin_popcount(mk);
            for (int i = 0; i < n; i++) {
                if (mk & (1 << i) &&
                    (num % (i + 1) == 0 || (i + 1) % num == 0)) {
                    f[mk] += f[mk ^ (1 << i)];
                }
            }
        }
        return f[(1 << n) - 1];
    }
};