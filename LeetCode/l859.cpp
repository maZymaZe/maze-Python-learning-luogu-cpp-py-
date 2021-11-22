class Solution {
   public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length())
            return false;
        int l = s.length();
        vector<int> dif;
        int c[26] = {0};
        for (int i = 0; i < l; i++) {
            if (s[i] != goal[i])
                dif.push_back(i);
            c[s[i] - 'a']++;
        }
        if (dif.size() == 0) {
            for (int i = 0; i < 26; i++) {
                if (c[i] > 1)
                    return true;
            }
            return false;
        }
        if (dif.size() == 2) {
            if (s[dif[0]] == goal[dif[1]] && s[dif[1]] == goal[dif[0]])
                return true;
        }
        return false;
    }
};