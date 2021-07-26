#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s;
int T, l, c1, ll;
vector<int> v;
int main() {
    cin >> T;
    while (T--) {
        cin >> s;
        l = s.length();
        v.clear();
        for (int i = 0; i < l; i++) {
            if (s[i] == '1' && (i == 0 || s[i - 1] == '0'))
                ll = i;
            if (s[i] == '1' && (i == l - 1 || s[i + 1] == '0'))
                v.push_back(i - ll + 1);
        }
        sort(v.begin(), v.end());
        l = v.size();
        c1 = 0;
        l--;
        while (l >= 0) {
            c1 += v[l];
            l -= 2;
        }
        cout << c1 << endl;
    }
    return 0;
}