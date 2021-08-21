class Solution {
   public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (const auto& x : strings) {
            string k(x);
            for (auto& c : k) {
                c = (c - x[0] + 26) % 26 + 'a';
            }
            mp[k].push_back(x);
        }
        for (auto& x : mp) {
            ans.push_back(x.second);
        }
        return ans;
    }
};