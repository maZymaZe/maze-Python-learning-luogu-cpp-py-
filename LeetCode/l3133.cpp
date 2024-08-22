class Solution {
   public:
    long long minEnd(int n, int x) {
        int c1[80] = {0}, c2[80] = {0}, c3[80] = {0}, p1 = 0, p2 = 0, p3 = 1;
        while (x) {
            c1[++p1] = (x & 1);
            x >>= 1;
        }
        n--;
        while (n) {
            c2[++p2] = (n & 1);
            n >>= 1;
        }
        int p4 = 1;
        while (p4 <= p2 || p3 <= p1) {
            if (p3 <= p1 && c1[p3] == 1) {
                c3[p3] = 1;
                p3++;
            } else if (p4 <= p2) {
                c3[p3] = c2[p4];
                p3++;
                p4++;
            } else {
                c3[p3] = c1[p3];
                p3++;
            }
        }
        long long ans = 0;
        for (int i = 1; i < p3; i++) {
            ans |= ((c3[i] * 1ll) << (i - 1));
        }
        return ans;
    }
};