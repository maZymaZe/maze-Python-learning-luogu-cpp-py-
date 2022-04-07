class Solution {
   public:
    string mergeAlternately(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length(), p1 = 0, p2 = 0;
        string ans;
        while (p1 < l1 && p2 < l2) {
            ans += word1[p1];
            p1++;
            ans += word2[p2];
            p2++;
        }
        ans += word1.substr(p1, l1);
        ans += word2.substr(p2, l2);
        return ans;
    }
};