class Solution {
   public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> p1, p2;
        int l1 = sentence1.size(), l2 = sentence2.size(), pre = 0;
        for (int i = 0; i < l1; i++) {
            if (sentence1[i] == ' ') {
                p1.push_back(sentence1.substr(pre, i - pre));
                pre = i + 1;
            }
        }
        p1.push_back(sentence1.substr(pre, l1));
        pre = 0;
        for (int i = 0; i < l2; i++) {
            if (sentence2[i] == ' ') {
                p2.push_back(sentence2.substr(pre, i - pre));
                pre = i + 1;
            }
        }
        p2.push_back(sentence2.substr(pre, l2));
        int c1 = 0, c2 = 0;
        l1 = p1.size(), l2 = p2.size();
        for (int i = 0; i < l1 && i < l2; i++) {
            if (p1[i] == p2[i])
                c1++;
            else
                break;
        }
        for (int i1 = l1 - 1, i2 = l2 - 1; i1 >= 0 && i2 >= 0; i1--, i2--) {
            if (p1[i1] == p2[i2])
                c2++;
            else
                break;
        }
        return c1 + c2 >= min(l1, l2);
    }
};