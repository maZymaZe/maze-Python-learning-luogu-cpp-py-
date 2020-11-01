class Solution {
   public:
    unordered_map<int, vector<string>> ans;
    unordered_set<string> wordset;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        wordset = unordered_set(wordDict.begin(), wordDict.end());
        backtrack(s, 0);
        return ans[0];
    }
    void backtrack(const string& s, int index) {
        if (!ans.count(index)) {
            if (index == s.size()) {
                ans[index] = {""};
                return;
            }

            ans[index] = {};
            for (int i = index + 1; i <= s.size(); i++) {
                string word = s.substr(index, i - index);
                if (wordset.count(word)) {
                    backtrack(s, i);
                    for (const string& succ : ans[i]) {
                        ans[index].push_back(succ.empty() ? word
                                                          : word + " " + succ);
                    }
                }
            }
        }
    }
};