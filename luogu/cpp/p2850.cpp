#include <cstdio>
#include <vector>
#include<cstring>
using namespace std;
const int NMAX = 507;
struct node {
    int dis, nx;
} f;
vector<node> mp[NMAX];
int sum[NMAX], fl[NMAX], flag;
void spfa(int k) {
    if (fl[k] == 1) {
        fl[k] = 0, flag = 1;
        return;
    }
    fl[k] = 1;
    if (!mp[k].empty()) {
        for (int i = 0; i < mp[k].size(); i++) {
            if (sum[mp[k][i].nx] > mp[k][i].dis + sum[k]) {
                sum[mp[k][i].nx] = mp[k][i].dis + sum[k];
                spfa(mp[k][i].nx);
                if (flag == 1) {
                    fl[k] = 0;
                    return;
                }
            }
        }
    }
    fl[k] = 0;
}
int main(){
    int t,n,m,w,x,y,z,k;scanf("%d", &t);
    while (t--){
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<=n;i++){mp[i].clear();}
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&x, &y,&z);
            f.dis=z; f.nx=y; mp[x].push_back(f);
            f.nx=x; mp[y].push_back(f);
        }
        for(int i=0; i<k;i++){
            scanf("%d%d%d", &x, &y, &z);
            f.dis=-z; f.nx=y; mp[x].push_back(f);
        }
        memset(sum, 0, sizeof(sum));
        flag=0;
        for(int i=1;i<=n;i++){
            spfa(i);if(flag)break;
        }
        printf(flag?"YES\n":"NO\n");
    }
    return 0;
}