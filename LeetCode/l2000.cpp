class Solution {
   public:
    string reversePrefix(string word, char ch) {
        auto it = word.begin();
        while (it != word.end() && *it != ch)
            ++it;
        if (it != word.end())
            ++it, reverse(word.begin(), it);
        return word;
    }
};