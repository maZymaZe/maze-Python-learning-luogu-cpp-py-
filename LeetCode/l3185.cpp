class Solution {
   public:
    long long countCompleteDayPairs(vector<int>& hours) {
        int cnt[24] = {0};
        for (int i : hours)
            cnt[i % 24]++;
        long long ans = (long long)(cnt[0] - 1) * cnt[0] / 2;
        for (int i = 1; i <= 11; i++)
            ans += (long long)cnt[i] * cnt[24 - i];
        ans += (long long)cnt[12] * (cnt[12] - 1) / 2;
        return ans;
    }
};