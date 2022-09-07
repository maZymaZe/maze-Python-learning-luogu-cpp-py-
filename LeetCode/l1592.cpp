class Solution {
   public:
    string reorderSpaces(string text) {
        int cnt = 0, l = text.length(), wc = 0, lp;
        for (int i = 0; i < l; i++) {
            if (text[i] == ' ')
                cnt++;
            if (text[i] != ' ' && (i == l - 1 || text[i + 1] == ' ')) {
                wc++;
                lp = i;
            }
        }
        wc--;
        int a = 0, b = 0;
        if (wc) {
            a = cnt / wc, b = cnt % wc;
        } else {
            b = cnt;
        }

        string ans;
        for (int i = 0; i < l; i++) {
            if (text[i] != ' ')
                ans += text[i];
            if (i == lp) {
                ans += string(b, ' ');
            } else if (text[i] != ' ' && text[i + 1] == ' ') {
                ans += string(a, ' ');
            }
        }
        return ans;
    }
};