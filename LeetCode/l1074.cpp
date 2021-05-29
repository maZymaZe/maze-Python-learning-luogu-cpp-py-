class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size(),ans=0;
        vector<vector<int>> ps(n+1, vector<int>(m + 1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                ps[i][j]=ps[i][j-1]+matrix[i-1][j-1];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=i+1;j<=m;j++){
                unordered_map<int,int> mp;
                mp.clear();
                int pt=0;
                mp[0]=1;
                for(int k=1;k<=n;k++){
                    if(mp.count((ps[k][j]-ps[k][i])+pt-target)){
                        ans+=mp[(ps[k][j]-ps[k][i])+pt-target];
                    }
                    pt+=ps[k][j]-ps[k][i];
                    mp[pt]++;
                }
            }
        }
        return ans;
    }
};