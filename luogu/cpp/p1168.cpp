#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, t;
priority_queue<int, vector<int>, greater<int> > l;
priority_queue<int, vector<int>, less<int> > g;
int main()
{
    scanf("%d%d", &n, &t);
    int mid = t;
    printf("%d\n", mid);
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &t);
        if (!(i & 1))
        {
            l.push(t);
        }
        else
        {
            l.push(t);
            if (mid < l.top())
            {
                g.push(mid);
                mid = l.top();
                l.pop();
            }
            else
            {
                g.push(l.top());
                l.pop();
            }
            while (mid > l.top())
            {
                int p = l.top();
                l.pop();
                l.push(mid);
                mid = p;
            }
            while (mid < g.top())
            {
                int p = g.top();
                g.pop();
                g.push(mid);
                mid = p;
            }
            printf("%d\n", mid);
        }
    }
    return 0;
}