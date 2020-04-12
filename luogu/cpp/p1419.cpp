#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#define MAX 100004
using namespace std;
long long sum[MAX];
int L = -1e8, R = 1e8, a[MAX];
int n, s, t;
deque<int> Q;
int judge(int x) {
    memset(sum, 0, sizeof(0));
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + a[i] - x;
    }
    Q.clear();
    for (int i = s, p = 0; i <= n; ++i, ++p) {
        while (!Q.empty() && sum[Q.back()] > sum[p]) {
            Q.pop_back();
        }
        Q.push_back(p);
        while (Q.front() < i - t) {
            Q.pop_front();
        }
        if (sum[i] - sum[Q.front()] >= 0) return 1;
    }
    return 0;
}
int main() {
    scanf("%d%d%d", &n, &s, &t);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] *= 1e4;
    }
    int l = L, r = R, mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (judge(mid)) {
            l = mid;
        } else
            r = mid - 1;
    }
    printf("%.3lf", 1.0 * l / 10000);
    return 0;
}