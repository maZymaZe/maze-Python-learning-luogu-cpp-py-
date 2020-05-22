#include <algorithm>
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
int n, a[3000006], ans[3000006];
struct pr {
    int v, pos;
    bool operator<(const pr& x) { return v < x.v; }
};
vector<pr> s;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = n; i > 0; i--) {
        while (!s.empty() && s.back().v <= a[i]) s.pop_back();
        if (s.empty()) {
            s.push_back({a[i], i});
            ans[i] = 0;
        }
        else {
            ans[i]=s.back().pos;
            s.push_back({a[i], i});
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}