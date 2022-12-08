class Solution {
   public:
    bool checkPowersOfThree(int n) {
        int i = 1;
        while (i <= n)
            i *= 3;
        while (n) {
            i /= 3;
            if (n / i == 2)
                return false;
            n -= (n / i) * i;
        }
        return true;
    }
};