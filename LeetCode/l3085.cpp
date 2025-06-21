class Solution {
   public:
    int minimumDeletions(string word, int k) {
        int c[26] = {0};
        for (char ch : word) {
            c[ch - 'a']++;
        }
        int l = word.size(), ans = word.size();
        for (int i = 0; i <= l; i++) {
            int tm = i + k;
            int cur = 0;
            for (int j = 0; j < 26; j++) {
                if (c[j] > tm) {
                    cur += c[j] - tm;
                } else if (c[j] < i) {
                    cur += c[j];
                }
            }
            ans = min(ans, cur);
        }
        return ans;
    }
};