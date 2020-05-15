#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int rd[22][22],vis[23],val[23],n,mx=0;
vector<int> ans,res;
void dfs(int x,int tot){
    int f=1;
    for(int i=x+1;i<=n;i++){
        if(!vis[i]&&rd[x][i]){
            f=0;
            vis[i]=1;ans.push_back(i);
            dfs(i,tot+val[i]);
            vis[i]=0;ans.pop_back();
        }
    }
    if(f==1){
        if(tot>mx){
            mx=tot;
            res=ans;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&val[i]);
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=n-i;j++)
        scanf("%d",&rd[i][i+j]),
        rd[i+j][i]=rd[i][i+j];
    }
    for(int i=1;i<=n;i++){
        memset(vis, 0, sizeof(vis));
        ans.clear();
        ans.push_back(i);
        vis[i]=1;
        dfs(i,val[i]);
    }
    for(int i=0;i<res.size();i++){
        printf("%d ",res[i]);
    }
    printf("\n%d",mx);;
    return 0;
}