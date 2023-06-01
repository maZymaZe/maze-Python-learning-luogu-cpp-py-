class Solution {
   public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        vector<int> ans, ps;
        ps.push_back(0);
        string vowel = "aeiou";
        int c[256] = {0};
        for (char i : vowel)
            c[i] = 1;
        for (string& x : words) {
            int y = 0;
            if (c[x.front()] && c[x.back()]) {
                y = 1;
            }
            ps.push_back(ps.back() + y);
        }
        for (auto& v : queries) {
            ans.push_back(ps[v[1] + 1] - ps[v[0]]);
        }
        return ans;
    }
};