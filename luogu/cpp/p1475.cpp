#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int pa = 0, n,m, t1, t2, t3,mp[109][109],cnt[103],f[103],own[103];
void dfs(int x){
    if(f[x])return;
    f[x]=1;
    for(int i=m;i>0;i--){
        cnt[i]+=mp[x][i];
        if(cnt[i]>50){
            own[i]=1;
            dfs(i);
        }
    }
}
int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        mp[t1][t2]=t3;
        m=max(max(t1,t2),m);
    }
    for(int i=1;i<=m;i++){
        memset(f,0,sizeof(f));
        memset(own,0,sizeof(own));
        memset(cnt, 0, sizeof(cnt));
        dfs(i);
        for(int j=1;j<=m;j++){
            if(own[j]&&i!=j){
                printf("%d %d\n",i,j);
            }
        }
    }
    return 0;
}