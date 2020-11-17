int r1, c1;
bool cmp(const vector<int>& a, const vector<int>& b) {
    return abs(a[0] - r1) + abs(a[1] - c1) < abs(b[0] - r1) + abs(b[1] - c1);
}
class Solution {
   public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        r1 = r0, c1 = c0;
        vector<vector<int>> ans;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                ans.push_back({i, j});
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        return ans;
    }
};