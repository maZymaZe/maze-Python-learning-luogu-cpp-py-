class Solution {
   public:
    string clearDigits(string s) {
        int l = s.size();
        string ans;
        for (int i = 0; i < l; i++) {
            if (isdigit(s[i])) {
                if (!ans.empty())
                    ans.pop_back();
            } else
                ans.push_back(s[i]);
        }
        return ans;
    }
};