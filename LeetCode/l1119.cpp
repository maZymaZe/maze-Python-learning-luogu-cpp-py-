class Solution {
   public:
    string removeVowels(string s) {
        string ans;
        for (auto c : s) {
            if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
                ans += c;
        }
        return ans;
    }
};