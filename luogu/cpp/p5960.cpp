#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n, m;
const int NMAX = 5020;
struct EDGE {
    int x, y, z;
} e[NMAX];
int dis[NMAX];
bool bf(int s) {
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    for (int t = 1; t <= n; t++) {
        for (int i = 1; i <= m; i++) {
            dis[e[i].y] = min(dis[e[i].y], dis[e[i].x] + e[i].z);
        }
    }
    for (int i = 1; i <= m; i++)
        if (dis[e[i].x] + e[i].z < dis[e[i].y])
            return false;
    return true;
}
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &e[i].y, &e[i].x, &e[i].z);
    }
    if (bf(1))
        for (int i = 1; i <= n; i++) {
            printf("%d%c", dis[i], i < n ? ' ' : '\n');
        }
    else
        printf("NO\n");
    return 0;
}