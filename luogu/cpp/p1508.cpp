#include<cstdio>
int r,l,ans,sc[203][203]={0},mp[203][203]={0},u[203][203]={0},n,m,d[4]={0,1,0,-1};
void dfs(int x,int y,int now){
    if(x==0)return;
    else {
        for(int i=1;i<=3;i++){
            if(y+d[i]<=n&&y+d[i]>0)
                if(u[x][y+d[i]]==0||(u[x][y+d[i]]&&now+mp[x][y+d[i]]>sc[x][y+d[i]])){
                    sc[x][y+d[i]]=now+mp[x][y+d[i]];
                    u[x][y+d[i]]=1;
                    dfs(x-1,y+d[i],now+mp[x][y+d[i]]);
                }
        }
    }
}
int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&mp[i][j]);
        }
    }
    dfs(m,n/2+1,0);
    if(n/2+1>m)l=n/2+1-m,r=n/2+1+m;
    else l=1,r=n;
    ans=sc[1][l];
    for(int i=l+1;i<=r;i++){
        if(sc[1][i]>ans)ans=sc[1][i];
    }
    printf("%d",ans);
    return 0;
}