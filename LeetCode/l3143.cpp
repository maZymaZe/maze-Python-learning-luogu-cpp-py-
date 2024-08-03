class Solution {
   public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int t[26] = {0}, l = s.size(), lim = 1e9 + 7, ti[26];
        for (int i = 0; i < 26; i++)
            t[i] = lim;
        for (int i = 0; i < l; i++) {
            points[i][0]=abs(points[i][0]),points[i][1]=abs(points[i][1]);
            if (max(points[i][0], points[i][1]) < t[s[i] - 'a']) {
                t[s[i] - 'a'] = max(points[i][0], points[i][1]);
                ti[s[i] - 'a'] = i;
            }
        }
        for (int i = 0; i < l; i++) {
            if (ti[s[i] - 'a'] == i)
                continue;
            lim = min(lim, max(points[i][0], points[i][1]) - 1);
        }
        int ans = 0;
        for (int i = 0; i < l; i++) {
            if (max(points[i][0], points[i][1]) <= lim) {
                ans++;
            }
        }
        return ans;
    }
};