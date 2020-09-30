class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int n=A.size(),m=A[0].size();
        int cnt,tot=0;
        for(int i=0;i<m;i++){
            cnt=0;
            for(int j=0;j<n;j++){
                cnt+=A[j][i]^A[j][0];
            }
            cnt=max(cnt,n-cnt);
            tot+=cnt*(1<<(m-i-1));
        }
        return tot;
    }
};