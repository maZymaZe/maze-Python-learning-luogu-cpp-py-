class Solution {
   public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans;
        int l = mat.size(), mx = 0, pos = 0;
        for (int i = 0; i < l; i++) {
            int x = 0;
            for (int j : mat[i])
                x += j;
            if (x > mx)
                mx = x, pos = i;
        }
        ans.push_back(pos);
        ans.push_back(mx);
        return ans;
    }
};