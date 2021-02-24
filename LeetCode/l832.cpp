class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n=A.size(),m=A[0].size();
        int t=m/2;
        for(int i=0;i<n;i++){
            for(int j=0;j<t;j++){
                swap(A[i][j],A[i][m-1-j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                A[i][j]^=1;
            }
        }
        return A;
    }
};