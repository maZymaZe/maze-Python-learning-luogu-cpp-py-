#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <vector>
using namespace std;
const int NMAX = 2e5 + 10;
struct SOC {
    int val, id, adc;
} s[NMAX];
bool cmp1(const SOC& a, const SOC& b) {
    return a.val < b.val;
}
bool cmp2(const SOC& a, const SOC& b) {
    return a.id < b.id;
}
unordered_map<int, vector<int> > mp;
int n, m, t, ans = 0, u = 0, cc[NMAX];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t);
        if (!mp.count(t))
            mp.insert({t, vector<int>()});
        mp[t].push_back(i);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &s[i].val);
        s[i].adc = 0, s[i].id = i;
    }
    sort(s + 1, s + 1 + m, cmp1);
    for (int i = 1; i <= m; i++) {
        int x = s[i].val, tc = 0, f = 0;
        while (!mp.count(x)) {
            if (x == 1) {
                if (f == 0)
                    f = 1;
                else
                    break;
            }
            x = (x + 1) / 2;
            tc++;
        }
        if (mp.count(x)) {
            u += tc;
            ans++;
            s[i].adc = tc;
            cc[mp[x].back()] = s[i].id;
            if (mp[x].size() == 1)
                mp.erase(x);
            else
                mp[x].pop_back();
        }
    }
    sort(s + 1, s + 1 + m, cmp2);
    printf("%d %d\n", ans, u);
    for (int i = 1; i < m; i++)
        printf("%d ", s[i].adc);
    printf("%d\n", s[m].adc);
    for (int i = 1; i <= n; i++)
        printf("%d ", cc[i]);
    return 0;
}