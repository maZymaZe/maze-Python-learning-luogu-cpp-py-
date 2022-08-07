class Solution {
   public:
    char findKthBit(int n, int k) {
        int len[26] = {0};
        len[1] = 1;
        for (int i = 2; i <= n; i++) {
            len[i] = len[i - 1] * 2 + 1;
        }
        int bs = 0;
        for (int i = n; i > 1; i--) {
            if (k == len[i - 1] + 1)
                return (bs ^ 1) + '0';
            if (k > len[i - 1] + 1) {
                bs ^= 1;
                k = len[i] - k + 1;
            }
        }
        return bs + '0';
    }
};