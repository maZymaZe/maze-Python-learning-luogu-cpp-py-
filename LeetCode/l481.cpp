class Solution {
   public:
    int magicalString(int n) {
        vector<int> w(n + 100);
        w[1] = 1, w[2] = 2, w[3] = 2;
        int p = 3, f = 1, q = 4;
        while (q <= n) {
            if (w[p] == 1) {
                w[q++] = f;
                f ^= 3;
            } else {
                w[q++] = f;
                w[q++] = f;
                f ^= 3;
            }
            p++;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (w[i] == 1)
                ans++;
        }
        return ans;
    }
};