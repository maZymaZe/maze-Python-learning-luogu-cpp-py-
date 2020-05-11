#include <cstdio>
#include <cstring>
#include <iostream>
char q[30], z[30];
int l;
int fx(int x) {
    for (int i = 0; i < l; i++) {
        if (z[i] == q[x]) return i;
    }
    return 0;
}
void dfs(int l1, int r1, int l2, int r2) {
    if (l1 > r1 || l2 > r2) return;
    if (l1 == r1) {
        printf("%c", z[l1]);
        return;
    }
    int y = fx(l2);
    if (y - 1 >= l1) dfs(l1, y - 1, l2 + 1, l2 + (y - l1));
    if (r1 >= y + 1) dfs(y + 1, r1, l2 + 1 + (y - l1), r2);

    printf("%c", q[l2]);
}
int main() {
    scanf("%s%s", z, q);
    l = strlen(z);
    dfs(0, l - 1, 0, l - 1);
    return 0;
}