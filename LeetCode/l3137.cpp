class Solution {
   public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int mx = 0, l = word.size();
        unordered_map<string, int> mp;
        for (int i = 0; i < l; i += k) {
            string s = word.substr(i, k);
            mp[s]++;
            mx = max(mx, mp[s]);
        }
        return l / k - mx;
    }
};