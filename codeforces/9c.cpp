#include <cstdio>
long long c, t;
void dfs(long long x) {
    if (x <= t) {
        c++;
        dfs(x * 10);
        dfs(x * 10 + 1);
    }
}
int main() {
    scanf("%lld", &t);
    dfs(1);
    printf("%lld\n", c);
    return 0;
}