#include <iostream>
using namespace std;
long long T, a, b;
int main() {
    cin >> T;
    while (T--) {
        cin >> a >> b;
        if (a == b + 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}