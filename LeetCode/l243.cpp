class Solution {
   public:
    int shortestDistance(vector<string>& wordsDict,
                         string word1,
                         string word2) {
        int l = wordsDict.size();
        int p = 0, q = 0;
        while (word1 != wordsDict[p])
            p++;
        while (word2 != wordsDict[q])
            q++;
        int ans = abs(p - q);
        while (p < l && q < l) {
            if (p < q) {
                p++;
                while (p < l && word1 != wordsDict[p])
                    p++;
                if (p == l)
                    break;
            } else {
                q++;
                while (q < l && word2 != wordsDict[q])
                    q++;
                if (q == l)
                    break;
            }
            ans = min(ans, abs(p - q));
        }
        return ans;
    }
};