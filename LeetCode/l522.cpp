class Solution {
   public:
    bool isSubsequence(string& x, string& y) {
        int j = 0;
        for (int i = 0; i < y.length() && j < x.length(); i++)
            if (x[j] == y[i])
                j++;
        return j == x.length();
    }

    int findLUSlength(vector<string>& strs) {
        int l = strs.size(), ans = -1;
        for (int i = 0; i < l; i++) {
            int f = 1;
            for (int j = 0; j < l; j++) {
                if (j == i)
                    continue;
                if (isSubsequence(strs[i], strs[j])) {
                    f = 0;
                    break;
                }
            }
            if (f)
                ans = max(ans, (int)strs[i].size());
        }
        return ans;
    }
};