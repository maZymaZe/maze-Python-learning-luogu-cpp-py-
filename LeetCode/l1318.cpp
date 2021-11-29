class Solution {
   public:
    int minFlips(int a, int b, int c) {
        int ta[40] = {0}, tb[40] = {0}, tc[40] = {0};
        int p = 0;
        while (a) {
            ta[++p] = a % 2;
            a /= 2;
        }
        p = 0;
        while (b) {
            tb[++p] = b % 2;
            b /= 2;
        }
        p = 0;
        while (c) {
            tc[++p] = c % 2;
            c /= 2;
        }
        int ans = 0;
        for (int i = 1; i < 40; i++) {
            if ((ta[i] | tb[i]) != tc[i]) {
                if (tc[i] == 1)
                    ans++;
                else
                    ans += ta[i] + tb[i];
            }
        }
        return ans;
    }
};