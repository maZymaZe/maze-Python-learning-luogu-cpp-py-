#include <iostream>
#include <stack>
#include <string>
using namespace std;
string s;
stack<int> st;
int a[1000030];
int main() {
    cin >> s;
    int l = s.size(), cnt = 0;
    for (int i = 0; i < l; i++) {
        if (s[i] == '(')
            st.push(i);
        if (s[i] == ')') {
            if (!st.empty()) {
                a[st.top()] = 1;
                a[i] = 1;
                st.pop();
            }
        }
    }
    int ans = 0, w = 0, tot = 0;
    for (int i = 0; i <= l; i++) {
        if (a[i])
            w++;
        else
            ans = max(w, ans), w = 0;
    }
    for (int i = 0; i <= l; i++) {
        if (a[i])
            w++;
        else {
            if (w == ans)
                tot++;
            w = 0;
        }
    }
    if (ans) {
        cout << ans << ' ' << tot << endl;
    } else
        cout << "0 1" << endl;
    return 0;
}