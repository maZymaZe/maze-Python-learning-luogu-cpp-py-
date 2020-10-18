class Solution {
   public:
    int countLargestGroup(int n) {
        int cnt[40] = {0}, ma = 0, p[10200] = {0};
        for (int i = 1; i <= n; i++) {
            int t = i, tot = 0;
            while (t) {
                tot += t % 10;
                t /= 10;
            }
            cnt[tot]++;
        }
        for (int i = 1; i < 40; i++) {
            p[cnt[i]]++;
        }
        for (int i = 1; i < 10000; i++) {
            if (p[i])
                ma = p[i];
        }
        return ma;
    }
};