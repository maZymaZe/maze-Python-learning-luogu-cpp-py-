#include <cstdio>
long long max(long long a, long long b){return a>b?a:b;}
const int NMAX = 1e5 + 10;
int n, k;
long long a[NMAX], s[NMAX];
long long q[NMAX],f[NMAX][2];
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        s[i] = a[i] + s[i - 1];
    }
    int tail=1,head=1;
    for(int i=1;i<=n;i++){
        f[i][0]=max(f[i-1][1],f[i-1][0]);
        while(q[head]<i-k&&head<=tail)head++;
        f[i][1]=f[q[head]][0]-s[q[head]]+s[i];
        while(f[i][0]-s[i]>f[q[tail]][0]-s[q[tail]]&&head<=tail)tail--;
        q[++tail]=i;
    }
    printf("%lld",max(f[n][0],f[n][1]));
    return 0;
}