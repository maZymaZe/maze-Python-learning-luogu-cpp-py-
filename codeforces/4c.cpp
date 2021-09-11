#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
string s;
int n;
unordered_map<string, int> mp;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (!mp.count(s)) {
            cout << "OK" << endl;
            mp.insert({s, 1});
        } else {
            cout << s << (mp[s]++) << endl;
        }
    }
    return 0;
}