class NumMatrix {
public:
    vector<vector<int>> ps;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==0)return;
        int m=matrix[0].size();
        ps.push_back(vector<int>(m+1));
        for(int i=1;i<=n;i++){
            ps.push_back(vector<int>(m+1));
            for(int j=1;j<=m;j++){
                ps[i][j]=(long long)matrix[i-1][j-1]+ps[i-1][j]-ps[i-1][j-1]+ps[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return (long long)ps[row2+1][col2+1]-ps[row1][col2+1]-ps[row2+1][col1]+ps[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */