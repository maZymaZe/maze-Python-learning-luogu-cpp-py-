class Solution {
   public:
    vector<string> splitWordsBySeparator(vector<string>& words,
                                         char separator) {
        vector<string> ans;
        for (const string& word : words) {
            int l = word.size();
            int pre = 0;
            for (int i = 0; i <= l; i++) {
                if (i == l || word[i] == separator) {
                    if (i - pre > 0) {
                        ans.push_back(word.substr(pre, i - pre));
                    }
                    pre = i + 1;
                }
            }
        }
        return ans;
    }
};