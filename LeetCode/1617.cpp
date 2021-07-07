class Solution {
public:
    int ff(int x,vector<int> &f){
        if(f[x]==x)return x;
        return f[x]=ff(f[x],f);
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int> ans(n-1);
        int limit=1<<n;
        int dp[17][17]={0};
        memset(dp,0x3f, sizeof(dp));
        for(int i=0; i<n-1; i++){
            dp[edges[i][0]][edges[i][1]]=1;
            dp[edges[i][1]][edges[i][0]]=1;
        }
        for(int k=1; k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+ dp[k][j]);
                }
            }
        }
        vector<int> v,f(n+1),vis(n+1);
        for(int i=0;i<limit;i++){
            v.clear();
            for(int j=1;j<=n;j++)f[j]=j,vis[j]=0;
            for(int j=0;j<n;j++){
                if(i&(1 << j))v.push_back(j+1),vis[j+1]=1;
            }           
            if(v.size()<2)continue;
            for(int j=0;j<n-1;j++){
                if(vis[edges[j][0]]&&vis[edges[j][1]]){
                    f[ff(edges[j][0],f)]=ff(edges[j][1],f);
                }
            }
            int rt=ff(v[0],f),len=v.size(),flag= 0;
            for(int j=0;j<len;j++){
                if(ff(v[j],f)!=rt){
                    flag=1;
                    break;
                }
            }
            if(flag)continue;
            int mx=0;
            for(int j=0;j<len;j++){
                for(int k=j+1;k<len;k++){
                    mx=max(mx,dp[v[j]][v[k]]);
                }
            }
            ans[mx-1]++;
            
        }
        return ans;
    }
};