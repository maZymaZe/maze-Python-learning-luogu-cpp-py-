#include <cstdio>
int ans = 0, x1, x2, x3, y1, y2, y3;
int main() {
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
    ans = 3;
    int t = 3;
    if (x1 == x2 && !(y1 < y2 ? (y2 > y3 && y3 > y1) : (y1 > y3 && y3 > y2)))
        t = 2;
    if (x1 == x3 && !(y1 < y3 ? (y3 > y2 && y2 > y1) : (y1 > y2 && y2 > y3)))
        t = 2;
    if (x3 == x2 && !(y3 > y2 ? (y3 > y1 && y1 > y2) : (y2 > y1 && y1 > y3)))
        t = 2;
    if (y1 == y2 && !(x1 < x2 ? (x2 > x3 && x3 > x1) : (x1 > x3 && x3 > x2)))
        t = 2;
    if (y1 == y3 && !(x1 < x3 ? (x3 > x2 && x2 > x1) : (x1 > x2 && x2 > x3)))
        t = 2;
    if (y3 == y2 && !(x3 > x2 ? (x3 > x1 && x1 > x2) : (x2 > x1 && x1 > x3)))
        t = 2;

    if (ans > t)
        ans = t;

    if ((x1 == x2 && x1 == x3) || (y1 == y2 && y1 == y3))
        t = 1;
    if (ans > t)
        ans = t;

    printf("%d", ans);
    return 0;
}