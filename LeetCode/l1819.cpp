class Solution {
   public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        const int NMAX = 2e5 + 4;
        vector<int> c(NMAX);
        for (auto i : nums)
            c[i]++;
        int ans = 0;
        for (int i = 1; i < NMAX; i++) {
            int x = -1;
            for (int j = i; j < NMAX; j += i) {
                if (c[j])
                    x == -1 ? x = j : x = __gcd(x, j);
            }
            ans += i == x;
        }
        return ans;
    }
};