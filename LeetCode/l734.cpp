class Solution {
   public:
    bool areSentencesSimilar(vector<string>& sentence1,
                             vector<string>& sentence2,
                             vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size())
            return false;
        set<pair<string, string>> s;
        int ll = similarPairs.size();
        for (int i = 0; i < ll; i++) {
            s.insert(make_pair(similarPairs[i][0], similarPairs[i][1]));
            s.insert(make_pair(similarPairs[i][1], similarPairs[i][0]));
        }
        int l = sentence1.size();
        for (int i = 0; i < l; i++) {
            if (sentence1[i] == sentence2[i])
                ;
            else if (!s.count(make_pair(sentence1[i], sentence2[i])))
                return false;
        }
        return true;
    }
};