bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}
class Solution {
   public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        unordered_map<int, vector<int>> mp;
        int l = items.size();
        for (int i = 0; i < l; i++)
            mp[items[i][0]].push_back(items[i][1]);
        vector<vector<int>> ans;
        for (auto i : mp) {
            sort(i.second.begin(), i.second.end());
            int tot = 0, ll = i.second.size();
            for (int j = 1; j <= 5; j++) {
                tot += i.second[ll - j];
            }
            ans.push_back({i.first, tot / 5});
        }
        sort(ans.begin(), ans.end(), cmp);
        return ans;
    }
};