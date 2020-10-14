#include <cstdio>
int n, y = 1900, num[10], m = 1, now = 7;
int main() {
    scanf("%d", &n);
    while (y < 1900 + n) {
        now %= 7;
        num[now]++;
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 ||
            m == 12)
            now += 31;
        if (m == 2) {
            if (y % 400 == 0)
                now += 29;
            else if (y % 100 == 0)
                now += 28;
            else if (y % 4 == 0)
                now += 29;
            else
                now += 28;
        }
        if (m == 4 || m == 6 || m == 9 || m == 11)
            now += 30;
        m++;
        if (m == 13) {
            m = 1;
            y++;
        }
    }
    for (int i = 0; i <= 6; i++)
        printf("%d ", num[i]);
    return 0;
}