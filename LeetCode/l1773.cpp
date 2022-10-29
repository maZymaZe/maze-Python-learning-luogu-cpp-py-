class Solution {
   public:
    int countMatches(vector<vector<string>>& items,
                     string ruleKey,
                     string ruleValue) {
        int p = -1, c = 0;
        if (ruleKey == "type")
            p = 0;
        else if (ruleKey == "color")
            p = 1;
        else
            p = 2;
        for (auto& x : items) {
            c += (x[p] == ruleValue);
        }
        return c;
    }
};