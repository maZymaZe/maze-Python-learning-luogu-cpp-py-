class Solution {
   public:
    int minValidStrings(vector<string>& words, string target) {
        int lt = target.length();
        vector<int> maxjump(lt);
        for (const string& w : words) {
            string tmp = w + '#' + target;
            int l = tmp.length();
            vector<int> nextjump(l);
            nextjump[0] = -1;
            for (int i = 1; i < l; i++) {
                int j = nextjump[i - 1];
                while (tmp[j + 1] != tmp[i] && j >= 0) {
                    j = nextjump[j];
                }
                if (tmp[j + 1] == tmp[i]) {
                    nextjump[i] = j + 1;
                } else
                    nextjump[i] = -1;
            }
            int m = w.size();
            for (int i = 0; i < lt; i++) {
                maxjump[i] = max(maxjump[i], nextjump[i + m + 1] + 1);
            }
        }
        vector<int> dp(lt + 1, 0);
        for (int i = 1; i <= lt; i++) {
            dp[i] = 1e9;
        }
        for (int i = 0; i < lt; i++) {
            dp[i + 1] = dp[i + 1 - maxjump[i]] + 1;
            if (dp[i + 1] > lt) {
                return -1;
            }
        }
        return dp[lt];
    }
};