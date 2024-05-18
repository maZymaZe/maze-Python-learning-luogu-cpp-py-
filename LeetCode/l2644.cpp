class Solution {
   public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int ans = divisors[0], s = -1;
        for (int i : divisors) {
            int t = 0;
            for (int j : nums) {
                if (j % i == 0)
                    t++;
            }
            if (t > s || (t == s && i < ans))
                ans = i, s = t;
        }
        return ans;
    }
};