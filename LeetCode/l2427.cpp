class Solution {
   public:
    int commonFactors(int a, int b) {
        int ans = 0, x = min(a, b);
        for (int i = 1; i <= x; i++) {
            if (a % i == 0 && b % i == 0)
                ans++;
        }
        return ans;
    }
};