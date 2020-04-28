#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n, m, indegree[30], h[30], flag;
vector<int> l, r;
struct edge {
    int u, v, nx;
};
vector<edge> edges;
int topo(int pr = 0) {
    deque<int> dq;
    int f = 0, t = 0;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) dq.push_back(i), t++;
    }
    if (dq.size() > 1) f = 1;
    while (!dq.empty()) {
        int cnt = 0;
        int hd = dq.front();
        if (pr == 1) printf("%c", hd + 'A');
        for (int i = h[hd]; i; i = edges[i].nx) {
            indegree[edges[i].v]--;
            if (indegree[edges[i].v] == 0) {
                dq.push_back(edges[i].v), t++;
                cnt++;
            }
        }
        if (cnt > 1) f = 1;
        dq.pop_front();
    }
    if (t != n) return -1;
    if (f == 1) return 0;
    return 1;
}
int main() {
    string s;
    cin >> n >> m;
    edges.push_back({0, 0});
    for (int i = 0; i < m; i++) {
        cin >> s;
        l.push_back(s[0] - 'A');
        r.push_back(s[2] - 'A');
        edges.push_back({l[i], r[i]});
        edges[i + 1].nx = h[edges[i + 1].u];
        h[edges[i + 1].u] = i + 1;
        memset(indegree, 0, sizeof(indegree));
        for (int j = 0; j <= i; j++) indegree[r[j]]++;
        flag = topo();
        if (flag == 0) continue;
        if (flag == 1) {
            printf("Sorted sequence determined after %d relations: ", i + 1);
            memset(indegree, 0, sizeof(indegree));
            for (int j = 0; j <= i; j++) indegree[r[j]]++;
            topo(1);
            printf(".");
            break;
        }
        if (flag == -1) {
            printf("Inconsistency found after %d relations.", i + 1);
            break;
        }
    }
    if (flag == 0) {
        printf("Sorted sequence cannot be determined.");
    }
    return 0;
}