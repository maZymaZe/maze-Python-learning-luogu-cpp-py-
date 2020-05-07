#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int ans=-1,mp[3300], f[3300], n, m, a[3300], gg, w[3300], wp = 0, vis[3300];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (i == 0) gg = a[i];
        for (int j = 0; j <= m; j++) {
            if (a[i] - j > 0) {
                mp[a[i] - j] = 1;
                gg = __gcd(gg, a[i] - j);
            }
        }
    }
    if (mp[1] || gg > 1) {
        printf("-1");
    } else {
        memset(f, 0x3f, sizeof(f));
        f[0] = 0;
        for (int i = 2; i <= 3000; i++) {
            if (mp[i]) w[wp++] = i;
        }
        int mod = w[0], k = -1;
        while (1) {
            k = -1;
            for (int i = 0; i < mod; i++)
                if (!(vis[i]) && (k == -1 || f[i] < f[k])) k = i;
            if (k == -1) break;
            vis[k] = 1;
            for (int i = 1; i < wp; i++){
                int t1=(k+w[i])%mod;
                if(!vis[t1])f[t1]=min(f[t1],f[k]+w[i]);
            } 
        }
        for(int i=1;i<mod;i++)ans=max(ans,f[i]-mod);
        printf("%d",ans);
    }
    return 0;
}