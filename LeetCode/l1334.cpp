class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> f(n,vector<int>(n,0x3f3f3f3f));
        int l=edges.size();
        for(int i=0;i<l;i++){
            f[edges[i][1]][edges[i][0]]=edges[i][2];
            f[edges[i][0]][edges[i][1]]=edges[i][2];
        }
        for(int i=0;i<n;i++)f[i][i]=0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                }
            }
        }
        vector<int> cn(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(f[i][j]<=distanceThreshold)cn[i]++;
            }
        }
        int mi=0x3f3f3f3f,ans=0;
        for(int i=0;i<n;i++){
            if(cn[i]<=mi){
                mi=cn[i];
                ans=i;
            }
        }
        return ans;
    }
};