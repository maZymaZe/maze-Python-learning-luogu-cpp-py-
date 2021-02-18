class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=1; i<n;i++){
            for(int j=0; j<n; j++){
                int mi=matrix[i-1][j];
                if(j)mi=min(mi,matrix[i-1][j-1]);
                if(j!=n-1)mi=min(mi,matrix[i-1][j+1]);
                matrix[i][j]+=mi;
            }
        }
        int ans=matrix[n-1][0];
        for(int i=1;i<n;i++)ans=min(ans,matrix[n-1][i]);
        return ans;
    }
};