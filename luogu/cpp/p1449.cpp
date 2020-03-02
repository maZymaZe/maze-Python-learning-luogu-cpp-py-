#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <stack>
using namespace std;
int pt = 0, nf = 0, t1, t2, t;
string ls;
int si(int w, int l)
{
    t = 0;
    for (int i = 0; i < l; i++)
    {
        t += (int)(ls[w + i] - '0') * pow(10, l - 1 - i);
    }
    return t;
}
int main()
{

    stack<int> nb;
    cin >> ls;
    for (int i = 0; i < ls.size(); i++)
    {
        if (ls[i] == '@')
        {
            printf("%d", nb.top());
        }
        else if (ls[i] == '.')
        {
            if (ls[i - 1] <= '9' && ls[i - 1] >= '0')
            {
                nb.push(si(nf, i - nf));
            }
            nf = i + 1;
        }
        else if (ls[i] == '+')
        {
            nf = i + 1;
            t1 = nb.top();
            nb.pop();
            t2 = nb.top();
            nb.pop();
            nb.push(t1 + t2);
        }
        else if (ls[i] == '-')
        {
            nf = i + 1;
            t1 = nb.top();
            nb.pop();
            t2 = nb.top();
            nb.pop();
            nb.push(t2 - t1);
        }
        else if (ls[i] == '*')
        {
            nf = i + 1;
            t1 = nb.top();
            nb.pop();
            t2 = nb.top();
            nb.pop();
            nb.push(t1 * t2);
        }
        else if (ls[i] == '/')
        {
            nf = i + 1;
            t1 = nb.top();
            nb.pop();
            t2 = nb.top();
            nb.pop();
            nb.push(t2 / t1);
        }
    }
    return 0;
}