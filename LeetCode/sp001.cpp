#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> vec(m);
        long long left = 0, right = -1e9;
        for (int i = 0; i < n; ++i) {
            long long sum = 0, mx = 0;
            for (int j = 0; j < m; ++j) {
                cin >> vec[j];
                sum += vec[j];
                mx = max(mx, sum);
            }
            long long l = max(left + mx, right + sum);
            sum = mx = 0;
            for (int j = m - 1; j >= 0; --j) {
                sum += vec[j];
                mx = max(mx, sum);
            }
            long long r = max(right + mx, left + sum);
            left = l;
            right = r;
        }
        cout << max(left, right) << endl;
    }
    return 0;
}
