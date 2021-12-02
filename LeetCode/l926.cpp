class Solution {
   public:
    int minFlipsMonoIncr(string S) {
        int cnt0 = 0, len = S.size(), cnt1 = 0;
        int ans = len;
        for (auto x : S)
            if (x == '0')
                cnt0++;
        for (int i = 0; i < len; i++) {
            ans = min(ans, cnt0 + cnt1);
            if (S[i] == '0')
                cnt0--;
            else
                cnt1++;
        }
        ans = min(ans, cnt0 + cnt1);
        return ans;
    }
};