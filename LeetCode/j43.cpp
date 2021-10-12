class Solution {
   public:
    int countDigitOne(int n) {
        int ans = 0;
        for (long long i = 1; i <= n; i *= 10) {
            long long dv = i * 10;
            ans += (n / dv) * i + min(max(n % dv - i + 1, 0LL), i);
        }
        return ans;
    }
};