class Solution {
   public:
    bool isAcronym(vector<string>& words, string s) {
        string t;
        for (const auto& word : words)
            t += word[0];
        return t == s;
    }
};