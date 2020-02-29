#include <cstdio>
int n, b[300] = {1}, tot = 0, k;
int sc(int i, int s, int c)
{
    int g = 0, a;
    if (s == 1)
        g = 1;
    else
        for (a = c; a <= i / s; a++)
            g += sc(i - a, s - 1, a);
    return g;
}

int main()
{
    scanf("%d%d", &n, &k);
    printf("%d", sc(n, k, 1));
    return 0;
}