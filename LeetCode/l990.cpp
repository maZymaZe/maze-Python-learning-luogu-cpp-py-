int t, f[1000], b[506 * 3];
struct node {
    int x, y, e;
    bool operator<(const node& x) { return e > x.e; }
} a[506];
int ff(int x) {
    if (f[x] == x)
        return x;
    else
        return f[x] = ff(f[x]);
}
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int flag = 1;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(f,0,sizeof(f));
        int tot = 0,n=equations.size();
        for (int i = 0; i < n; i++) {
            a[i+1].x=equations[i][0];
            a[i+1].y=equations[i][3];
            a[i+1].e=(equations[i][1]=='=');
            b[++tot] = a[i+1].x;
            b[++tot] = a[i+1].y;
        }
        sort(b + 1, b + tot + 1);
        int tott = unique(b + 1, b + tot + 1) - b;
        for (int i = 1; i <= n; i++) {
            a[i].x = lower_bound(b + 1, b + 1 + tott, a[i].x) - b;
            a[i].y = lower_bound(b + 1, b + tott + 1, a[i].y) - b;
        }
        for (int i = 1; i <= tott; i++) f[i] = i;
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i++) {
            if (a[i].e == 1) {
                int f1 = ff(a[i].x), f2 = ff(a[i].y);
                if (f1 != f2) {
                    f[f1] = f2;
                }
            } else {
                int f1 = ff(a[i].x), f2 = ff(a[i].y);
                if (f1 == f2) {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag)
           return true;
        else
            return false;
    }
};