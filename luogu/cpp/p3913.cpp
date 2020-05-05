#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, t1, t2;
int x[100006], y[100006];
inline int read() {  
    char ch = getchar();
    int x = 0, f = 1;
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int main() {
    n= read();m= read();
    long long ans = 0,cx=1,cy=1;
    for (int i = 1; i <= m; i++) {
        x[i]= read();y[i]= read();
    }
    sort(x+1,x+1+m);
    sort(y+1,y+1+m);
    for(int i=1;i<m;i++){
        if(x[i]!=x[i+1])cx++;
        if(y[i]!=y[i+1])cy++;
    }
    ans = ans + (long long)cy * n + (long long)(n - cy) * cx;

    printf("%lld", ans);
    return 0;
}
