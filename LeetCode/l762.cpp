class Solution {
   public:
    int countPrimeSetBits(int left, int right) {
        int c[40] = {0}, ans = 0;
        c[2] = c[3] = c[5] = c[7] = c[11] = c[13] = c[17] = c[19] = c[23] =
            c[29] = c[31] = 1;
        for (int i = left; i <= right; i++) {
            int x = i, t = 0;
            while (x) {
                x -= ((-x) & x), t++;
            }
            if (c[t])
                ans++;
        }
        return ans;
    }
};