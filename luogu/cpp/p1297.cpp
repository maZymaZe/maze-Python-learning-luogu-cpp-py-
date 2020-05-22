#include <cstdio>
inline int max(int a, int b){ return a > b ? a : b;}
int n,A,B,C,a[10000007];
int main() {
    double ans=0;
    
    scanf("%d%d%d%d%d", &n, &A, &B, &C, a+1);
    for (int i = 2; i <= n; i++)
        a[i] = ((long long)a[i - 1] * A + B) % 100000001;
    for (int i = 1; i <= n; i++) a[i] = a[i] % C + 1;
    ans=1.0/(double)max(a[n],a[1]);
    for(int i=2;i<=n;i++){
        ans+=1.0/(double)max(a[i],a[i-1]);
    }
    printf("%.3lf",ans);
    return 0;
}