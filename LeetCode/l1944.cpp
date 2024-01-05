class Solution {
   public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> s;
        int l = heights.size();
        vector<int> ans(l);
        for (int i = l - 1; i >= 0; i--) {
            int tot = 0;
            while (!s.empty() && s.back() < heights[i]) {
                tot++;
                s.pop_back();
            }
            if (!s.empty())
                tot++;
            ans[i] = tot;
            s.push_back(heights[i]);
        }
        return ans;
    }
};