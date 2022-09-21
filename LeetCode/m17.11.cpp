class Solution {
   public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int p1 = -1, p2 = -1, l = words.size();
        int ans = l;
        for (int i = 0; i < l; i++) {
            if (words[i] == word1) {
                if (p2 != -1)
                    ans = min(ans, i - p2);
                p1 = i;
            } else if (words[i] == word2) {
                if (p1 != -1)
                    ans = min(ans, i - p1);
                p2 = i;
            }
        }
        return ans;
    }
};