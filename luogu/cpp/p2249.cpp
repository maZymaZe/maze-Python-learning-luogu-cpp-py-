#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000006], n, m, t,ans;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &t);
        ans=lower_bound(a+1,a+1+n,t)-a;
        if(t!=a[ans])printf("-1 ");
        else printf("%d ",ans);
    }
    return 0;
}