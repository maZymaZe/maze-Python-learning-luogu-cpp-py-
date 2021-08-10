#include <algorithm>
#include <iostream>
using namespace std;
long long a, b, c, d;
int main() {
    cin >> a >> b >> c >> d;
    long long gd = __gcd(c, d);
    c /= gd;
    d /= gd;

    cout << min(a / c, b / d) << endl;
    return 0;
}