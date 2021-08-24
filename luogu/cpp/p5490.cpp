#include <algorithm>
#include <cstdio>
using namespace std;
#define lson (x << 1)
#define rson (x << 1 | 1)
const int NMAX = 1e6 + 10;
int n;
struct JOB {
    int y, x1, x2, type;
    bool operator<(const JOB& other) const { return y < other.y; }
} job[NMAX];
int xx[NMAX];
struct SegTree {
    int l, r, sum;
    long long len;
} tree[NMAX << 2];

void build(int x, int l, int r) {
    tree[x].l = l, tree[x].r = r;

    tree[x].sum = tree[x].len = 0;

    if (l == r)
        return;
    int mid = (l + r) / 2;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}
void pushup(int x) {
    int l = tree[x].l, r = tree[x].r;
    if (tree[x].sum) {
        tree[x].len = xx[r + 1] - xx[l];
    } else {
        tree[x].len = tree[lson].len + tree[rson].len;
    }
}
void edit_tree(int x, int L, int R, int c) {
    int l = tree[x].l, r = tree[x].r;
    if (xx[l] >= R || xx[r + 1] <= L)
        return;
    if (L <= xx[l] && xx[r + 1] <= R) {
        tree[x].sum += c;
        pushup(x);
        return;
    }
    edit_tree(lson, L, R, c);
    edit_tree(rson, L, R, c);
    pushup(x);
}
int main() {
    scanf("%d", &n);
    for (int i = 1, t1, t2, t3, t4; i <= n; i++) {
        scanf("%d%d%d%d", &t1, &t2, &t3, &t4);
        job[i * 2 - 1] = {t2, t1, t3, 1};
        job[i * 2] = {t4, t1, t3, -1};
        xx[i * 2 - 1] = t1, xx[i * 2] = t3;
    }
    n <<= 1;
    sort(job + 1, job + 1 + n);
    sort(xx + 1, xx + 1 + n);
    int tot = unique(xx + 1, xx + 1 + n) - xx - 1;
    build(1, 1, tot - 1);

    long long ans = 0;
    for (int i = 1; i < n; i++) {
        edit_tree(1, job[i].x1, job[i].x2, job[i].type);
        ans += tree[1].len * (job[i + 1].y - job[i].y);
    }
    printf("%lld\n", ans);
    return 0;
}