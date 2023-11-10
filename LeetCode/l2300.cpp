class Solution {
   public:
    vector<int> successfulPairs(vector<int>& spells,
                                vector<int>& potions,
                                long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for (int i : spells) {
            ans.push_back(potions.end() - lower_bound(potions.begin(),
                                                      potions.end(),
                                                      (success + i - 1) / i));
        }
        return ans;
    }
};