class Solution {
   public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        vector<string> ans;
        for (string& s : words) {
            if (s.size() != num.size())
                continue;
            string t;
            for (char c : s) {
                if (c >= 'a' && c <= 'c')
                    t += '2';
                else if (c >= 'd' && c <= 'f')
                    t += '3';
                else if (c >= 'g' && c <= 'i')
                    t += '4';
                else if (c >= 'j' && c <= 'l')
                    t += '5';
                else if (c >= 'm' && c <= 'o')
                    t += '6';
                else if (c >= 'p' && c <= 's')
                    t += '7';
                else if (c >= 't' && c <= 'v')
                    t += '8';
                else if (c >= 'w' && c <= 'z')
                    t += '9';
                else
                    t += '?';
            }
            if (t == num)
                ans.push_back(s);
        }
        return ans;
    }
};