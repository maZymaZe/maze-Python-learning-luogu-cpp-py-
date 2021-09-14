#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s;
vector<string> ipt;

int main() {
    int stat = 0, mxl = -1;
    while (getline(cin, s)) {
        ipt.push_back(s);
        mxl = max(mxl, (int)s.size());
    }
    int tl = mxl + 2;
    cout << string(tl, '*') << endl;
    for (auto x : ipt) {
        if ((mxl - x.size()) % 2 == 0) {
            int sp = (mxl - x.size()) / 2;
            cout << '*' << string(sp, ' ') << x << string(sp, ' ') << '*'
                 << endl;
        } else {
            int sp = (mxl - x.size()) / 2;
            if (!stat) {
                cout << '*' << string(sp, ' ') << x << string(sp + 1, ' ')
                     << '*' << endl;
            } else {
                cout << '*' << string(sp + 1, ' ') << x << string(sp, ' ')
                     << '*' << endl;
            }
            stat ^= 1;
        }
    }
    cout << string(tl, '*') << endl;
    return 0;
}