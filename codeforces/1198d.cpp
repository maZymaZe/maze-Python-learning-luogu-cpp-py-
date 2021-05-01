#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
const int NMAX = 55 + 10;
int n, f[NMAX][NMAX][NMAX][NMAX];
string s;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= n; j++) {
            f[i][j][i][j] = (s[j - 1] == '#');
        }
    }
    for (int x1 = 1; x1 <= n; x1++) {
        for (int y1 = 1; y1 <= n; y1++) {
            for (int x2 = x1; x2 <= n; x2++) {
                for (int y2 = y1; y2 <= n; y2++) {
                    if (x1 != x2 || y1 != y2) {
                        f[x1][y1][x2][y2] = max(x2 - x1 + 1, y2 - y1 + 1);
                    }
                }
            }
        }
    }
    for (int x1 = n; x1 > 0; x1--) {
        for (int x2 = x1; x2 <= n; x2++) {
            for (int y1 = n; y1 > 0; y1--) {
                for (int y2 = y1; y2 <= n; y2++) {
                    for (int k = x1; k < x2; k++) {
                        f[x1][y1][x2][y2] =
                            min(f[x1][y1][x2][y2],
                                f[x1][y1][k][y2] + f[k + 1][y1][x2][y2]);
                    }
                    for (int k = y1; k < y2; k++) {
                        f[x1][y1][x2][y2] =
                            min(f[x1][y1][x2][y2],
                                f[x1][y1][x2][k] + f[x1][k + 1][x2][y2]);
                    }
                }
            }
        }
    }
    cout << f[1][1][n][n] << endl;
    return 0;
}