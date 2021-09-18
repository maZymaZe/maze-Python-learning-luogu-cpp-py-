#include <iostream>
#include <string>
using namespace std;
int main() {
    int n, m, ans = 0;
    char c;
    int u[400] = {0};
    cin >> n >> m >> c;
    string mp[100];
    for (int i = 0; i < n; i++) {
        cin >> mp[i];
    }
    u[c] = 1;
    u['.'] = 1;
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == c) {
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k], ny = j + dy[k];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                        continue;
                    if (u[mp[nx][ny]] == 0)
                        ans++, u[mp[nx][ny]] = 1;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}