class Solution {
   public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1,
                                          vector<vector<int>>& items2) {
        vector<vector<int>> ans;
        int p1 = 0, p2 = 0, l1 = items1.size(), l2 = items2.size();
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        };
        sort(items1.begin(), items1.end(), cmp);
        sort(items2.begin(), items2.end(), cmp);
        while (p1 < l1 && p2 < l2) {
            if (items1[p1][0] == items2[p2][0]) {
                ans.push_back({items1[p1][0], items1[p1][1] + items2[p2][1]});
                p1++, p2++;
            } else if (items1[p1][0] < items2[p2][0]) {
                ans.push_back({items1[p1][0], items1[p1][1]});
                p1++;
            } else {
                ans.push_back({items2[p2][0], items2[p2][1]});
                p2++;
            }
        }
        while (p1 < l1)
            ans.push_back(items1[p1]), p1++;
        while (p2 < l2)
            ans.push_back(items2[p2]), p2++;
        return ans;
    }
};