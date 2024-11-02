class Solution {
   public:
    int minChanges(int n, int k) {
        int c1[50] = {0}, c2[50] = {0};
        int p = 0;
        while (n) {
            c1[++p] = n % 2;
            n /= 2;
        }
        p = 0;
        while (k) {
            c2[++p] = k % 2;
            k /= 2;
        }
        int ans = 0;
        for (int i = 1; i <= 40; i++) {
            if (c1[i] && !c2[i])
                ans++;
            else if (!c1[i] && c2[i])
                return -1;
        }
        return ans;
    }
};