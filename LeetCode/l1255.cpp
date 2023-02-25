class Solution {
   public:
    int maxScoreWords(vector<string>& words,
                      vector<char>& letters,
                      vector<int>& score) {
        int n = words.size(), res = 0;
        vector<int> c(26);
        for (char s : letters) {
            c[s - 'a']++;
        }
        for (int i = 1; i < (1 << n); i++) {
            vector<int> wc(26);
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    for (char s : words[j])
                        wc[s - 'a']++;
                }
            }
            bool flag = 1;
            int rs = 0;
            for (int j = 0; j < 26; j++) {
                rs += score[j] * wc[j];
                flag = flag && (wc[j] <= c[j]);
            }
            if (flag)
                res = max(res, rs);
        }
        return res;
    }
};