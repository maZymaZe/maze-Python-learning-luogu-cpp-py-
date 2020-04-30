#include <cstdio>
#include <cstring>
int a, b, c, t, v[1005][1005];
struct con {
    int l, r, pre, w, s;
} vc[10006];
void op(int tail) {
    printf("%d ", vc[tail].s);
    int q[3000], qp = 1;
    for (int i = tail; i; i = vc[i].pre) {
        q[qp++] = vc[i].w;
    }
    for (int i = vc[tail].s; i >= 1; i--) {
        printf("%d ", q[i]);
    }
}
int main() {
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        memset(v, 0, sizeof(v));
        memset(vc, 0, sizeof(vc));
        v[0][0] = 1;
        scanf("%d%d%d", &a, &b, &c);
        if (c == 0) {
            printf("0\n");
            continue;
        }
        if (b == c) {
            printf("1 2\n");
            continue;
        }
        int head = 0, tail = 0;
        while (head <= tail) {
            if (vc[head].l != a && !v[a][vc[head].r]) {
                tail++;
                vc[tail].l = a;
                vc[tail].r = vc[head].r;
                vc[tail].pre = head;
                vc[tail].s = vc[head].s + 1;
                vc[tail].w = 1;
                v[a][vc[head].r] = 1;
            }
            if (vc[head].r != b && !v[vc[head].l][b]) {
                tail++;
                vc[tail].l = vc[head].l;
                vc[tail].r = b;
                vc[tail].pre = head;
                vc[tail].s = vc[head].s + 1;
                vc[tail].w = 2;
                v[vc[head].l][b] = 1;
            }

            if (vc[head].l != 0 && !v[0][vc[head].r]) {
                tail++;
                vc[tail].l = 0;
                vc[tail].r = vc[head].r;
                vc[tail].pre = head;
                vc[tail].s = vc[head].s + 1;
                vc[tail].w = 3;
                v[0][vc[head].r] = 1;
            }
            if (vc[head].r != 0 && !v[vc[head].l][0]) {
                tail++;
                vc[tail].l = vc[head].l;
                vc[tail].r = 0;
                vc[tail].pre = head;
                vc[tail].s = vc[head].s + 1;
                vc[tail].w = 4;
                v[vc[head].l][0] = 1;
            }
            if (vc[head].l != a && vc[head].r > 0) {
                if (a - vc[head].l >= vc[head].r) {
                    if (!v[vc[head].r + vc[head].l][0]) {
                        tail++;
                        vc[tail].l = vc[head].l + vc[head].r;
                        vc[tail].r = 0;
                        vc[tail].pre = head;
                        vc[tail].s = vc[head].s + 1;
                        vc[tail].w = 5;
                        v[vc[head].l + vc[head].r][0] = 1;
                    }
                } else if (!v[a][vc[head].r + vc[head].l - a]) {
                    tail++;
                    vc[tail].l = a;
                    vc[tail].r = vc[head].l + vc[head].r - a;
                    vc[tail].pre = head;
                    vc[tail].s = vc[head].s + 1;
                    vc[tail].w = 5;
                    v[a][vc[head].r + vc[head].l - a] = 1;
                    if (vc[head].r + vc[head].l - a == c) {
                        op(tail);
                        continue;
                    }
                }
            }
            if (vc[head].r != b && vc[head].l > 0) {
                if (b - vc[head].l >= vc[head].r) {
                    if (!v[0][vc[head].r + vc[head].l]) {
                        tail++;
                        vc[tail].r = vc[head].l + vc[head].r;
                        vc[tail].l = 0;
                        vc[tail].pre = head;
                        vc[tail].s = vc[head].s + 1;
                        vc[tail].w = 6;
                        v[0][vc[head].l + vc[head].r] = 1;
                        if (vc[head].r + vc[head].l == c) {
                            op(tail);
                            continue;
                        }
                    }
                } else if (!v[vc[head].r + vc[head].l - b][b]) {
                    tail++;
                    vc[tail].r = b;
                    vc[tail].l = vc[head].l + vc[head].r - b;
                    vc[tail].pre = head;
                    vc[tail].s = vc[head].s + 1;
                    vc[tail].w = 6;
                    v[vc[head].r + vc[head].l - b][b] = 1;
                }
            }
            head++;
        }
        printf("\n");
    }
    return 0;
}