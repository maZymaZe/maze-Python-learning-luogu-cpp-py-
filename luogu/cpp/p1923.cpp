#include <cstdio>
#include <cstdlib>
int n, m, a[5000005];
inline void swap(int &c, int &b) {
    int tmp = c;
    c = b;
    b = tmp;
}
void qsort(int l, int r) {
    int mid = a[(l + r) / 2], i = l, j = r;
    do {
        while (a[j] > mid) j--;
        while (a[i] < mid) i++;
        if (i <= j) swap(a[i],a[j]), i++, j--;
    } while (i <= j);
    if (m <= j)
        qsort(l, j);
    else if (m >= i)
        qsort(i, r);
    else {
        printf("%d", a[j + 1]);
        exit(0);
    }
}
int main() {
    scanf("%d%d", &n, &m);
    m++;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(1, n);
    return 0;
}