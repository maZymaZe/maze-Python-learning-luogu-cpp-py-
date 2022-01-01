class Solution {
   public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int l = original.size();
        if (l != m * n)
            return {};
        vector<vector<int>> v(m, vector<int>(n));
        for (int i = 0; i < l; i++)
            v[i / n][i % n] = original[i];
        return v;
    }
};