class Solution {
   public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int l = heights.size();
        vector<int> t(l);
        for (int i = 0; i < l; i++)
            t[i] = i;
        sort(t.begin(), t.end(), [&](const int& l, const int& r) {
            return heights[l] > heights[r];
        });
        vector<string> ans;
        for (int i = 0; i < l; i++)
            ans.push_back(names[t[i]]);
        return ans;
    }
};