class Solution {
   public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0, c[60] = {0};
        for (int i : time)
            c[i % 60]++;
        for (int i = 1; i < 30; i++)
            ans += c[i] * c[60 - i];
        ans += (long long)(c[30] - 1) * c[30] / 2;
        ans += (long long)(c[0] - 1) * c[0] / 2;
        return ans;
    }
};