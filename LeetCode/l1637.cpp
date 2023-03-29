class Solution {
   public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int l = points.size(), ans = 0;
        vector<int> v(l);
        for (int i = 0; i < l; i++)
            v[i] = points[i][0];
        sort(v.begin(), v.end());
        for (int i = 1; i < l; i++)
            ans = max(ans, v[i] - v[i - 1]);
        return ans;
    }
};