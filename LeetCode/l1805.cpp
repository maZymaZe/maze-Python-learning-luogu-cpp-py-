class Solution {
   public:
    int numDifferentIntegers(string word) {
        int len = word.size(), l = 0, r;
        set<string> s;
        while (l < len) {
            while (l < len && !isdigit(word[l]))
                l++;
            if (l >= len)
                break;
            r = l;
            while (r < len && isdigit(word[r]))
                r++;
            while (l < r - 1 && word[l] == '0')
                l++;
            s.insert(word.substr(l, r - l));
            l = r;
        }
        return s.size();
    }
};