class Solution {
   public:
    int findChampion(vector<vector<int>>& grid) {
        int l = grid.size();
        for (int i = 0; i < l; i++) {
            int c = 0;
            for (int j = 0; j < l; j++)
                c += (grid[i][j] == 0);
            if (c == 1)
                return i;
        }
        return -1;
    }
};