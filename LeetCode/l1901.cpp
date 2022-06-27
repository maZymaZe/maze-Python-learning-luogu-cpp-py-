class Solution {
   public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int up = 0, down = m - 1;
        while (up <= down) {
            int mid = (up + down) / 2;
            int maxUp = mid == 0 ? -1
                                 : *max_element(mat[mid - 1].begin(),
                                                mat[mid - 1].end());
            int maxBottom = mid + 1 == m ? -1
                                         : *max_element(mat[mid + 1].begin(),
                                                        mat[mid + 1].end());
            auto it = max_element(mat[mid].begin(), mat[mid].end());
            if (*it >= max(maxUp, maxBottom)) {
                return {mid, int(it - mat[mid].begin())};
            } else if (maxUp >= max(*it, maxBottom)) {
                down = mid;
            } else {
                up = mid + 1;
            }
        }
        return {};
    }
};
