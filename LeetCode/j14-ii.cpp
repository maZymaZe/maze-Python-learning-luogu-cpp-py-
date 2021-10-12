class Solution {
   public:
    int cuttingRope(int n) {
        if (n <= 3)
            return n - 1;
        long ret = 1;
        if (n % 3 == 1) {
            ret = 4;
            n = n - 4;
        }
        if (n % 3 == 2) {
            ret = 2;
            n = n - 2;
        }
        while (n) {
            ret = ret * 3 % 1000000007;
            n = n - 3;
        }
        return (int)ret;
    }
};
