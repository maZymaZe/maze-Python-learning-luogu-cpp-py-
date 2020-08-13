#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int MAXN = 5e4 + 5;
int n, m, cnt[MAXN] = {0}, a[MAXN] = {0}, len;
long long tot = 0, ans1[MAXN] = {0}, ans2[MAXN] = {0};
struct question {
    int l, r, in, id;
} q[MAXN];
bool cmp(const question& a, const question& b) {
    if (a.in ^ b.in)
        return a.in < b.in;
    return (a.in & 1) ? a.r < b.r : a.r > b.r;
}
inline void ins(int x) {
    tot -= (long long)cnt[a[x]] * cnt[a[x]];
    cnt[a[x]]++;
    tot += (long long)cnt[a[x]] * cnt[a[x]];
}
inline void del(int x) {
    tot -= (long long)cnt[a[x]] * cnt[a[x]];
    cnt[a[x]]--;
    tot += (long long)cnt[a[x]] * cnt[a[x]];
}
/*inline bool IsDigit(char c) {
    return (c >= '0' && c <= '9');
}
inline int Read() {
    int sum = 0, f = 1;
    char c = 0;
    while (!IsDigit(c)) {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (IsDigit(c)) {
        sum = (sum << 3) + (sum << 1) + c - '0';
        c = getchar();
    }
    return sum * f;
}*/
inline void Write(long long x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    static int sta[35];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    } while (x);
    while (top)
        putchar(sta[--top] + 48);
}

inline int Read() {
    register int x=1,ans=0;register char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') x*=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ans=(ans<<3)+(ans<<1)+ch-48;ch=getchar();}
    return x*ans;
}

int main() {
    n = Read(), m = Read();
    for (int i = 1; i <= n; i++)
        a[i] = Read();

    len = sqrt(n);
    for (register int i = 1; i <= m; i++) {
        q[i].l = Read(), q[i].r = Read();
        q[i].id = i, q[i].in = (q[i].l-1)/len+1;
    }
    sort(q + 1, q + 1 + m, cmp);
    int l = 1, r = 0, nl, nr;
    for (register int i = 1; i <= m; i++) {
        if (q[i].l == q[i].r) {
            ans1[q[i].id] = 0, ans2[q[i].id] = 1;
            continue;
        }
        nl = q[i].l;
        nr = q[i].r;
        while (l > nl)
            ins(--l);
        while (l < nl)
            del(l++);
        while (r > nr)
            del(r--);
        while (r < nr)
            ins(++r);

        ans1[q[i].id] = (long long)tot - (r - l + 1);
        ans2[q[i].id] = (long long)(r - l + 1) * (r - l);

        if (ans1[q[i].id] == 0) {
            ans2[q[i].id] = 1;
            continue;
        }
        long long g = __gcd(ans1[q[i].id], ans2[q[i].id]);
        ans1[q[i].id] /= g, ans2[q[i].id] /= g;
    }
    for (register int i = 1; i <= m; i++) {
        printf("%lld/%lld\n",ans1[i],ans2[i]);
    }
    return 0;
}