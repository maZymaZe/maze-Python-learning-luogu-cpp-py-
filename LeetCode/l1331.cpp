class Solution {
   public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        auto v = arr;
        sort(v.begin(), v.end());
        vector<int> ans;
        auto it = unique(v.begin(), v.end());
        for (auto x : arr) {
            ans.push_back(lower_bound(v.begin(), it, x) - v.begin() + 1);
        }
        return ans;
    }
};