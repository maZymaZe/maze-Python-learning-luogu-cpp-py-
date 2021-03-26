#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int NMAX=1e3+10;
int mp[NMAX][NMAX],bel[NMAX][NMAX],tm[NMAX][NMAX],n,m,qq;
struct pr {
    int x,y;
};
queue<pr> q;
bool ok(const pr &x){
    return x.x>0&&x.x<=n&&x.y>0&&x.y<=m;
}
int main() {
    memset(bel,-1,sizeof(bel));
    scanf("%d%d%d",&n,&m,&qq);
    for(int i=1;i<=n;i++){
        for(int j= 1; j <=m;j++)
        scanf("%1d",&mp[i][j]);
    }
    for(int i=1;i<=n;i++){
        for(int j= 1; j <=m;j++){
            int tmp=0;
            if(i>1)tmp|=(mp[i][j]==mp[i-1][j]);
            if(j>1)tmp|=(mp[i][j]==mp[i][j-1]);
            if(i<n)tmp|=(mp[i][j]==mp[i+1][j]);
            if(j<m)tmp|=(mp[i][j]==mp[i][j+1]);
            if(tmp){
                bel[i][j]=mp[i][j];
                q.push({i,j});
            }
        }
    }
    while(!q.empty()){
        pr tx=q.front();q.pop();
        pr t;
        t= {tx.x+1,tx.y};
        if(ok(t)&&bel[t.x][t.y]==-1){
            q.push(t);
            bel[t.x][t.y]=bel[tx.x][tx.y];
            tm[t.x][t.y]=tm[tx.x][tx.y]+1;
        }
        t= {tx.x,tx.y+1};
        if(ok(t)&&bel[t.x][t.y]==-1){
            q.push(t);
            bel[t.x][t.y]=bel[tx.x][tx.y];
            tm[t.x][t.y]=tm[tx.x][tx.y]+1;
        }
        t= {tx.x-1,tx.y};
        if(ok(t)&&bel[t.x][t.y]==-1){
            q.push(t);
            bel[t.x][t.y]=bel[tx.x][tx.y];
            tm[t.x][t.y]=tm[tx.x][tx.y]+1;
        }
        t= {tx.x,tx.y-1};
        if(ok(t)&&bel[t.x][t.y]==-1){
            q.push(t);
            bel[t.x][t.y]=bel[tx.x][tx.y];
            tm[t.x][t.y]=tm[tx.x][tx.y]+1;
        }
    }
    while(qq--){
        long long t1,t2,t3;
        scanf("%lld%lld%lld",&t1,&t2,&t3);
        if(tm[t1][t2]>t3||bel[t1][t2]==-1){
            printf("%d\n",mp[t1][t2]);
        }else{
            long long rr=t3-tm[t1][t2];
            if(rr&1)printf("%d\n",mp[t1][t2]^1);
            else printf("%d\n",mp[t1][t2]);
        }
    }
    return 0;
}