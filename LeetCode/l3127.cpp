class Solution {
   public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int c[2] = {0};
                for (int k = 0; k < 2; k++) {
                    for (int l = 0; l < 2; l++) {
                        if (grid[i + k][j + l] == 'B')
                            c[0]++;
                        else
                            c[1]++;
                    }
                }
                if (c[0] * c[1] < 4)
                    return true;
            }
        }
        return false;
    }
};