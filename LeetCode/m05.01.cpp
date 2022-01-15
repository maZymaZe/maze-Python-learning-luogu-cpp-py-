class Solution {
   public:
    int insertBits(int N, int M, int i, int j) {
        M <<= i;
        long long mask = (1ll << (j + 1)) - 1;
        mask = ~mask;
        mask |= ((1ll << (i)) - 1);
        N &= mask;
        N |= M;
        return N;
    }
};