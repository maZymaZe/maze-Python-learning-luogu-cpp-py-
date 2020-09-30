class Solution {
   public:
    int numberOf2sInRange(int n) {
        int q = 1, ans = 0;
        for (; q != 1000000000; q *= 10) {
            if (n / q % 10 < 2) {
                ans += (n - n % (q * 10)) / 10;
            } else if (n / q % 10 == 2) {
                ans += n % q + (n - n % (q * 10)) / 10 + 1;
            } else {
                ans += (n - n % (q * 10)) / 10 + q;
            }
        }
        return ans;
    }
};