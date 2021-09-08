#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct pr {
    int delta, pos;
    bool operator<(const pr& x) const { return delta > x.delta; }
};
priority_queue<pr> q;
string str;
int main() {
    int cnt = 0;
    long long ans = 0;
    cin >> str;
    int len = str.length();
    for (int i = 0, a, b; i < len && ans != -1; ++i) {
        if (str[i] == '(')
            ++cnt;
        else {
            --cnt;
            if (str[i] == '?') {
                scanf("%d%d", &a, &b);
                q.push({a - b, i});
                str[i] = ')';
                ans += b;
            }
        }
        if (cnt < 0) {
            if (q.empty())
                ans = -1;
            if (ans != -1) {
                cnt += 2;
                pr x = q.top();
                q.pop();
                str[x.pos] = '(';
                ans += x.delta;
            }
        }
    }
    if (cnt)
        ans = -1;
    cout << ans << endl;
    if (ans != -1)
        cout << str << endl;
    return 0;
}