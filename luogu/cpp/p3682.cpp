#include <cstdio>
const int NMAX = 1e5 + 10;
int n, fa[NMAX], tail[NMAX], tfa[NMAX], ans = 0;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &fa[i]);
       tail[fa[i]]=1;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tfa[i]);
       tail[tfa[i]]=1;
    }
    for (int i = 1; i <= n; i++) {
       if(fa[i])ans++;
       if(tfa[i])ans++;
       if(!tail[i])
       {
           int x=i;
           while(fa[x]==tfa[x]&&fa[x])ans-=2,x=fa[x];
       }
    }
    printf("%d\n",ans);
    return 0;
}