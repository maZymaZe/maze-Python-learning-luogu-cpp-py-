#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
long long ans = 0, cnt1 = 0, cnt2 = 0;
const int NMAX = 1e5 + 10;
int n, len[NMAX];
vector<vector<int>> mp;
vector<int> lid, lbg;
int main() {
    scanf("%d", &n);
    mp.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &len[i]);
        mp[i].resize(len[i]);
        for (int j = 0; j < len[i]; j++) {
            scanf("%d", &mp[i][j]);
        }
        int f = 0;
        for (int j = 1; j < len[i]; j++) {
            if (mp[i][j] > mp[i][j - 1]) {
                f = 1;
                break;
            }
        }
        if (f)
            cnt1++;
        else {
            cnt2++;
            lid.push_back(i);
            lbg.push_back(mp[i][0]);
        }
    }
    ans += cnt1 * n * 2 - cnt1 * cnt1;
    sort(lbg.begin(), lbg.end());
    for (int i = 0; i < cnt2; i++) {
        int idx =
            upper_bound(lbg.begin(), lbg.end(), mp[lid[i]][len[lid[i]] - 1]) -
            lbg.begin();
        ans+=cnt2-idx;
    }
    printf("%lld\n",ans);
    return 0;
}