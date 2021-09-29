#include <iostream>
#include <vector>
using namespace std;
int n, d, ans = 0;
vector<int> a;
int main() {
    cin >> n >> d;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++) {
        if (a[i] <= a[i - 1]) {
            int c = (a[i - 1] - a[i]) / d + 1;
            a[i] += c * d;
            ans += c;
        }
    }
    cout << ans << endl;
    return 0;
}