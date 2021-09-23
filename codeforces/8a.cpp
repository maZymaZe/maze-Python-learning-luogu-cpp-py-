#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string a, b, c;
int main() {
    cin >> a >> b >> c;
    bool fw = 0, bw = 0;
    if (a.find(b) <= a.size() && a.find(c, a.find(b) + b.size()) <= a.size())
        fw = 1;
    reverse(a.begin(), a.end());
    if (a.find(b) <= a.size() && a.find(c, a.find(b) + b.size()) <= a.size())
        bw = 1;
    if (fw && bw) {
        cout << "both" << endl;
    } else if (fw) {
        cout << "forward" << endl;
    } else if (bw) {
        cout << "backward" << endl;
    } else {
        cout << "fantasy" << endl;
    }
    return 0;
}