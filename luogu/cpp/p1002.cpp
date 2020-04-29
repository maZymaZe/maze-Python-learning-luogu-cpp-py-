#include<cstdio>
int dx[9]={0,1,-1,2,-2,1,-1,2,-2},dy[9]={0,2,-2,1,-1,-2,2,-1,1};
int n,m,x,y,mp[21][21]={0};
long long ans[21]={0};
int main(){
    scanf("%d%d%d%d",&n,&m,&x,&y);
    for(int i=0;i<9;i++){
        if(x+dx[i]<=n&&x+dx[i]>=0&&y+dy[i]<=m&&y+dy[i]>=0){
            mp[x+dx[i]][y+dy[i]]=1;
        }
    }
    for(int i=0;i<=m;i++){
        if(mp[0][i]==1)break;
        ans[i]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(j==0){
                if(mp[i][0]==1)ans[0]=0;
            }
            else{
                if(mp[i][j]==0)ans[j]+=ans[j-1];
                else ans[j]=0;
            }
        }
    }
    printf("%lld",ans[m]);
    return 0;
}