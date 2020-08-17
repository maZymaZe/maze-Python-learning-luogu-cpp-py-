#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int ans[100005], a, b, n;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a, &b);
        if(a == b){
            printf("0\n");continue;
        }
        memset(ans, 0, sizeof(ans));
        queue<int> q;
        q.push(a);
        ans[a] = 0;
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            if (t - 1 != a && t - 1 >= 0 && ans[t - 1] == 0) {
                ans[t - 1] = ans[t] + 1, q.push(t - 1);
                if (t - 1 == b)
                    break;
            }
            if (t + 1 != a && t + 1 < 100002 && ans[t + 1] == 0) {
                ans[t + 1] = ans[t] + 1, q.push(t + 1);
                if (t + 1 == b)
                    break;
            }
            if (2 * t != a && 2 * t < 100002 && ans[2 * t] == 0) {
                ans[2 * t] = ans[t] + 1, q.push(2 * t);
                if (2 * t == b)
                    break;
            }
        }
        printf("%d\n",ans[b]);
    }
    return 0;
}