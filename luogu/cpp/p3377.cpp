#include <cstdio>
#include <iostream>
using namespace std;

struct NODE {
    int value, id;
    bool operator<(const NODE& x) {
        return value < x.value || (value == x.value && id < x.id);
    }
};
struct TreeNode {
    int leftson, rightson, d;
    NODE node;
} tree[100010];
int n, m, f[100010], del[100010];
int find(int x) {
    if (f[x] == x)
        return x;
    else
        return f[x] = find(f[x]);
}
int merge(int x, int y) {
    if (!x)
        return y;
    if (!y)
        return x;
    if (tree[y].node < tree[x].node)
        swap(x, y);
    tree[x].rightson = merge(tree[x].rightson, y);
    if (tree[tree[x].rightson].d > tree[tree[x].leftson].d) {
        swap(tree[x].rightson, tree[x].leftson);
    }
    tree[x].d = tree[tree[x].rightson].d + 1;
    return x;
}
int remove(int x) {
    return merge(tree[x].leftson, tree[x].rightson);
}
int main() {
    tree[0].d = -1;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tree[i].node.value);
        f[i] = tree[i].node.id = i;
    }
    int t1, t2, pid, t3;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &t1, &t2);
        if (t1 == 1) {
            scanf("%d", &t3);
            if (del[t2] || del[t3])
                continue;
            int x = find(t2), y = find(t3);
            if (x != y)
                f[x] = f[y] = merge(x, y);
        } else {
            if (del[t2]) {
                printf("-1\n");
                continue;
            }
            int x = find(t2);
            printf("%d\n", tree[x].node.value);
            pid = remove(x);
            f[tree[x].leftson] = f[tree[x].rightson] = f[x] = pid;
            del[x] = 1;
        }
    }
    return 0;
}