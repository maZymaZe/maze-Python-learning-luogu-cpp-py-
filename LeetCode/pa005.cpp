#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1005;
int n, g[N][N], a, b, k;

bool check(int x) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int dij =
                min({g[i][j], g[i][a] + x + g[b][j], g[i][b] + x + g[a][j]});
            if (dij + x >= k)
                return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> g[i][j];
    cin >> a >> b >> k;

    int l = 0, r = k;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }

    if (!check(0))
        cout << "-1\n";
    else
        cout << l << endl;

    return 0;
}