#include <queue>
#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
int n, t, m;
string s;
priority_queue<int, vector<int>, greater<int> > l;
priority_queue<int, vector<int>, less<int> > g;
int main()
{
    scanf("%d%d", &n, &t);
    int mid = t;
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &t);
        if (!(i & 1))
        {
            l.push(t);
            while ((!l.empty()) && mid > l.top())
            {
                int p = l.top();
                l.pop();
                l.push(mid);
                mid = p;
            }
            while ((!g.empty()) && mid < g.top())
            {
                int p = g.top();
                g.pop();
                g.push(mid);
                mid = p;
            }
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
            while ((!l.empty()) && mid > l.top())
            {
                int p = l.top();
                l.pop();
                l.push(mid);
                mid = p;
            }
            while ((!g.empty()) && mid < g.top())
            {
                int p = g.top();
                g.pop();
                g.push(mid);
                mid = p;
            }
        }
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        if (s[0] == 'm')
        {
            printf("%d\n", mid);
        }
        else
        {
            n++;
            scanf("%d", &t);
            if (!(n & 1))
            {
                l.push(t);
                while ((!l.empty()) && mid > l.top())
                {
                    int p = l.top();
                    l.pop();
                    l.push(mid);
                    mid = p;
                }
                while ((!g.empty()) && mid < g.top())
                {
                    int p = g.top();
                    g.pop();
                    g.push(mid);
                    mid = p;
                }
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
                while ((!l.empty()) && mid > l.top())
                {
                    int p = l.top();
                    l.pop();
                    l.push(mid);
                    mid = p;
                }
                while ((!g.empty()) && mid < g.top())
                {
                    int p = g.top();
                    g.pop();
                    g.push(mid);
                    mid = p;
                }
            }
        }
    }
    return 0;
}