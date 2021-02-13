class Solution {
   public:
    vector<vector<int>> reconstructMatrix(int upper,
                                          int lower,
                                          vector<int>& colsum) {
        int l = colsum.size(), c0 = 0, c1 = 0;
        vector<vector<int>> ret(2, vector<int>(l));
        for (int i = 0; i < l; i++) {
            if (colsum[i] == 2) {
                c0++, c1++;
                ret[0][i] = ret[1][i] = 1;
            }
        }
        for (int i = 0; i < l; i++)
            if (colsum[i] == 1) {
                if (c0 < upper)
                    ret[0][i] = 1, c0++;
                else
                    ret[1][i] = 1, c1++;
            }
        if (c0 == upper && c1 == lower)
            return ret;
        return vector<vector<int>>();
    }
};