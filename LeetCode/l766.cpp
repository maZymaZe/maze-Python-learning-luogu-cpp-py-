class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int pre,n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++){
            pre=matrix[i][0];
            for(int j=0;j<n-i&&j<m;j++){
                if(matrix[i+j][j]!=pre)return false;
            }
        }
        for(int i=0;i<m;i++){
            pre=matrix[0][i];
            for(int j=0;j<m-i&&j<n;j++){
                if(matrix[j][i+j]!=pre)return false;
            }
        }
        return true;
    }
};