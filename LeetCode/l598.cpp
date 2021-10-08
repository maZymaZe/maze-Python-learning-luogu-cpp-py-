class Solution {
   public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int x = m, y = n;
        for (auto& i : ops) {
            x = min(i[0], x);
            y = min(i[1], y);
        }
        return x * y;
    }
};