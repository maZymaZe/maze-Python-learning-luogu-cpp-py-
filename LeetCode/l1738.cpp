class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(),m=matrix[0].size();
        vector<int> result;
        vector<int> dp(m);
        for(int i=0;i<n;i++){
            int t=matrix[i][0];
            dp[0]^=matrix[i][0];
            result.push_back(dp[0]);
            for(int j=1;j<m;j++){
                t^=matrix[i][j];
                dp[j]^=t;
                result.push_back(dp[j]);
            }
        }
         nth_element(result.begin(), result.begin() + k - 1, result.end(), greater<int>());
        return result[k - 1];
    }
};