class Solution {
   public:
    int leastMinutes(int n) {
        int t = 1, ans = 1;
        while (t < n)
            t <<= 1, ans++;
        return ans;
    }
};