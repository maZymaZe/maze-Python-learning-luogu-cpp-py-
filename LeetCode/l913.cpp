class Solution {
public:
    int dp[402][201][201];
    int n;
    int dfs(vector<vector<int>>& graph,int t,int x,int y){
        if(dp[t][x][y]!=-1)return dp[t][x][y];
        if(y==x)return dp[t][x][y]=2;
        if(x==0)return dp[t][x][y]=1;
        if(t==2*n)return dp[t][x][y]=0;
        if(t%2==0){
            bool cw=true;
            int l=graph[x].size();
            for(int i=0;i<l;i++){
                int nx=graph[x][i];
                int tr=dfs(graph,t+1,nx,y);
                if(tr==1)return dp[t][x][y]=1;
                else if(tr!=2)cw=false;
            }
            if(cw)return dp[t][x][y]=2;
            else return dp[t][x][y]=0;
        }else{
            bool mw=true;
            int l=graph[y].size();
            for(int i=0;i<l;i++){
                int ny=graph[y][i];
                if(ny==0)continue;
                int tr=dfs(graph,t+1,x,ny);
                if(tr==2)return dp[t][x][y]=2;
                else if(tr!=1)mw=false;
            }
            if(mw)return dp[t][x][y]=1;
            else return dp[t][x][y]=0;
        }
    }
    int catMouseGame(vector<vector<int>>& graph) {
        n=graph.size();
        memset(dp, -1, sizeof(dp));
        return dfs(graph,0,1,2);
    }
};