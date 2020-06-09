#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int mp[220][220], qi[220][220], qj[220][220], n, m, mx = 0;
string s;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'X')
                mp[i][j + 1] = 1;
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n + 1; i++) {
            qi[i][j] = qi[i - 1][j] + mp[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m + 1; j++) {
            qj[i][j] = qj[i][j - 1] + mp[i][j];
        }
    }
    for (int l = 1; l <= m; l++) {
        for (int r = l; r <= m; r++) {
            int d = 1;
            while (d <= n) {
                while (!(qj[d][r] == qj[d][l - 1])) {
                    d++;
                    if (d > n)
                        break;
                }
                if (d > n)
                    continue;
                int e=d;
                while(e<=n&&qi[e][l]==qi[d-1][l]&&qi[e][r]==qi[d-1][r]){
                    if(qj[e][r]==qj[e][l-1]){
                        mx=max(mx,(r-l+1)*(e-d+1));
                    }
                    e++;
                }
                d=e;
            }
        }
    }
    cout<<mx<<endl;
    return 0;
}