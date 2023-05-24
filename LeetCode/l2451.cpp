class Solution {
   public:
    int cmp(string& a, string& b) {
        int n = a.size();
        for (int i = 1; i < n; i++) {
            if (a[i] - a[i - 1] != b[i] - b[i - 1])
                return 0;
        }
        return 1;
    }
    string oddString(vector<string>& words) {
        int l = words.size();
        if (cmp(words[0], words[1])) {
            for (int i = 2; i < l; i++) {
                if (!cmp(words[i], words[0]))
                    return words[i];
            }
        }
        if (cmp(words[0], words[2])) {
            return words[1];
        }
        return words[0];
    }
};