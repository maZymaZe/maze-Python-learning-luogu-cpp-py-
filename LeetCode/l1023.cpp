class Solution {
   public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for (auto& s : queries) {
            int l1 = s.size(), l2 = pattern.size(), p1 = 0, p2 = 0;
            int f = 1;
            while (p1 < l1) {
                if (s[p1] >= 'a' && s[p1] <= 'z') {
                    if (p2 < l2 && pattern[p2] == s[p1]) {
                        p2++, p1++;
                    } else
                        p1++;
                } else {
                    if (p2 < l2 && pattern[p2] == s[p1]) {
                        p1++, p2++;
                    } else {
                        ans.push_back(false);
                        f = 0;
                        break;
                    }
                }
            }
            if (!f)
                continue;
            ans.push_back(p2 == l2);
        }
        return ans;
    }
};