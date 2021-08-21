bool isd(char c) {
    return (c >= '0' && c <= '9');
}
class Solution {
   public:
    bool validWordAbbreviation(string word, string abbr) {
        int l1 = word.size(), l2 = abbr.size(), p1 = 0, p2 = 0;
        while (p1 < l1 && p2 < l2) {
            if (isd(abbr[p2])) {
                if (abbr[p2] == '0')
                    return false;
                int t = abbr[p2] - '0';
                p2++;
                while (p2 < l2) {
                    if (isd(abbr[p2])) {
                        t = t * 10 + abbr[p2] - '0';
                        p2++;
                    } else
                        break;
                }
                p1 += t;
            } else {
                if (abbr[p2] != word[p1]) {
                    return false;
                }
                p1++, p2++;
            }
        }
        return p1 == l1 && p2 == l2;
    }
};