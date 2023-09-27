class Solution {
   public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants,
                                  int veganFriendly,
                                  int maxPrice,
                                  int maxDistance) {
        vector<vector<int>> fr;
        for (auto& v : restaurants) {
            if (veganFriendly && !v[2]) {
                continue;
            }
            if (maxPrice < v[3])
                continue;
            if (maxDistance < v[4])
                continue;
            fr.push_back(v);
        }
        sort(fr.begin(), fr.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[1] == b[1])
                     return a[0] > b[0];
                 return a[1] > b[1];
             });
        vector<int> ans;
        for (auto& v : fr)
            ans.push_back(v[0]);
        return ans;
    }
};