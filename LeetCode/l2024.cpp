class Solution {
   public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int l = answerKey.length();
        vector<int> c;
        c.push_back(-1);
        for (int i = 0; i < l; i++)
            if (answerKey[i] == 'T')
                c.push_back(i);
        c.push_back(l);
        int ll = c.size(), ans = 0;
        if (ll - 2 <= k)
            return l;
        for (int i = 0; i + k + 1 < ll; i++) {
            ans = max(ans, c[i + k + 1] - c[i] - 1);
        }
        c.clear();
        c.push_back(-1);
        for (int i = 0; i < l; i++)
            if (answerKey[i] == 'F')
                c.push_back(i);
        c.push_back(l);
        ll = c.size();
        if (ll - 2 <= k)
            return l;
        for (int i = 0; i + k + 1 < ll; i++) {
            ans = max(ans, c[i + k + 1] - c[i] - 1);
        }
        return ans;
    }
};