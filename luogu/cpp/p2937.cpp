#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int n, m, a[102][102] = {0}, x1, y1, x2, y2, f = 0;
string s;
void turnit(int y, int x, int nu)
{
    int p = y, q = x;
    while (a[p][q] != -1)
    {
        if (a[p][q] == 0)
            a[p][q] = nu + 1;
        p++;
    }
    p = y, q = x;
    while (a[p][q] != -1)
    {
        if (a[p][q] == 0)
            a[p][q] = nu + 1;
        p--;
    }
    p = y, q = x;
    while (a[p][q] != -1)
    {
        if (a[p][q] == 0)
            a[p][q] = nu + 1;
        q++;
    }
    p = y, q = x;
    while (a[p][q] != -1)
    {
        if (a[p][q] == 0)
            a[p][q] = nu + 1;
        q--;
    }
}
int main()
{

    scanf("%d%d", &m, &n);
    getline(cin, s);
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= m + 1; j++)
        {
            a[i][j] = -1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        getline(cin, s);
        for (int j = 1; j <= m; j++)
        {
            if (s[j - 1] == '*')
                a[i][j] = -1;
            else
                a[i][j] = 0;
            if (f == 0 && s[j - 1] == 'C')
                x1 = i, y1 = j, f = 1;
            else if (f == 1 && s[j - 1] == 'C')
                x2 = i, y2 = j;
        }
    }
    int num = 1;
    a[x1][y1] = 1;
    while (a[x2][y2] == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] == num)
                {
                    turnit(i, j, num);
                }
            }
        }
        num++;
    }
    printf("%d", a[x2][y2] - 2);

    return 0;
}
