class Solution {
   public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        unordered_set<string> st;
        int l = words.size();
        string ans;
        for (int i = 0; i < l; i++) {
            if (words[i].size() == 1 ||
                st.count(words[i].substr(0, words[i].size() - 1))) {
                if (words[i].size() > ans.size() ||
                    (words[i].size() == ans.size() && words[i] < ans)) {
                    ans = words[i];
                }
                st.insert(words[i]);
            }
        }
        return ans;
    }
};