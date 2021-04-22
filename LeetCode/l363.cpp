class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n=matrix.size(),m=matrix[0].size(),ans=-0x3f3f3f3f;
        vector<vector<int>> ps(n+1,vector<int>(m + 1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ps[i+1][j+1]=ps[i+1][j]+matrix[i][j];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=i+1;j<=m; j++){
                set<int> s;
                s.insert(0);
                int tot=0;
                for(int l=1;l<=n;l++){
                    int tmp=ps[l][j]-ps[l][i];
                    tot+=tmp;
                    auto it=s.lower_bound(tot-k);
                    if(it!=s.end()){
                        ans=max(ans,tot-*it);
                    }
                    s.insert(tot);
                }
            }
        }
        return ans;
    }
};