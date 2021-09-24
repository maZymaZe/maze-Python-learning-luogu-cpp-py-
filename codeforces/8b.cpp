#include <iostream>
#include <string>
using namespace std;
const int NMAX = 300;
int mp[NMAX][NMAX], nx, ny;
string s;
int main() {
    cin >> s;
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    int x = 150, y = 150;
    mp[x][y] = 1;
    for (auto c : s) {
        if (c == 'U') {
            nx = x - 1, ny = y;
        } else if (c == 'D') {
            nx = x + 1, ny = y;
        } else if (c == 'L') {
            nx = x, ny = y - 1;
        } else if (c == 'R') {
            nx = x, ny = y + 1;
        }
        for (int i = 0; i < 4; i++) {
            int cx = nx + dx[i], cy = ny + dy[i];
            if (cx == x && cy == y)
                continue;
            if (mp[cx][cy]) {
                cout << "BUG" << endl;
                return 0;
            }
        }
        if (mp[nx][ny]) {
            cout << "BUG" << endl;
            return 0;
        } else
            mp[nx][ny] = 1;
        x = nx, y = ny;
    }
    cout << "OK" << endl;
    return 0;
}
