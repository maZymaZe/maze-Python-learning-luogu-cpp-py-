#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int d, p, c, f, s, t1, t2, t3, ep, book[600], h[600], ccnt[600], dis[600];
struct EDGE {
    int u, v, w, nx;
} e[600];

struct cmp {
    bool operator()(const int& a, const int& b) { return dis[a] < dis[b]; }
};
priority_queue<int, vector<int>, cmp> pq;
void add(int a, int b, int c) {
    e[++ep] = {a, b, c, h[a]};
    h[a] = ep;
}
int main() {
    scanf("%d%d%d%d%d", &d, &p, &c, &f, &s);
    for (int i = 1; i <= p; i++) {
        scanf("%d%d", &t1, &t2);
        add(t1, t2, d);
    }
    for (int i = 1; i <= f; i++) {
        scanf("%d%d%d", &t1, &t2, &t3);
        add(t1, t2, d - t3);
    }
    pq.push(s);
    book[s] = 1;
    dis[s] = d;
    ccnt[s]++;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        book[u] = 0;
        ccnt[u]++;
        if (ccnt[u] > c) {
            printf("-1");
            return 0;
        }
        for (int i = h[u]; i; i = e[i].nx) {
            if (dis[e[i].v] < dis[u] + e[i].w) {
                dis[e[i].v] = dis[u] + e[i].w;
                if (book[e[i].v] == 0) {
                    pq.push(e[i].v);
                    book[e[i].v] = 1;
                }
            }
        }
    }
    int maxx = 0;
    for (int i = 1; i <= c; i++) {
        if (dis[i] > maxx) {
            maxx = dis[i];
        }
    }
    printf("%d\n", maxx);
    return 0;
}