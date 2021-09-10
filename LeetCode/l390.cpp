class Solution {
   public:
    int lastRemaining(int n) {
        int s = 1, l = 1, d = 1;
        while (n > 1) {
            if (d || (n & 1) == 1)
                s += l;
            n >>= 1, l <<= 1;
            d ^= 1;
        }
        return s;
    }
};