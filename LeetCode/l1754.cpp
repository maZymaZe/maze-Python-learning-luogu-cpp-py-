class Solution {
   public:
    string largestMerge(string word1, string word2) {
        string merge;
        int i = 0, j = 0;
        while (i < word1.size() || j < word2.size()) {
            if (i < word1.size() && word1.substr(i) > word2.substr(j)) {
                merge.push_back(word1[i++]);
            } else {
                merge.push_back(word2[j++]);
            }
        }
        return merge;
    }
};
