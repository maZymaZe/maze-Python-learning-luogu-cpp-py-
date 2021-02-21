#include <iostream>
using namespace std;
long long n;
long long a[2][2] = {{3, 1}, {1, 3}};
long long b[2][2] = {{1, 0}, {0, 1}};
long long c[2][2];
const long long MOD = 1e9 + 7;
void qpow(long long x) {
    while (x) {
        if (x & 1) {
            c[0][0] = (a[0][0] * b[0][0] % MOD) + (a[0][1] * b[1][0] % MOD);
            c[0][1] = (a[0][0] * b[0][1] % MOD) + (a[0][1] * b[1][1] % MOD);
            c[1][0] = (a[1][0] * b[0][0] % MOD) + (a[1][1] * b[1][0] % MOD);
            c[1][1] = (a[1][0] * b[0][1] % MOD) + (a[1][1] * b[1][1] % MOD);
            b[0][0] = c[0][0] % MOD;
            b[0][1] = c[0][1] % MOD;
            b[1][0] = c[1][0] % MOD;
            b[1][1] = c[1][1] % MOD;
        }
        c[0][0] = (a[0][0] * a[0][0] % MOD) + (a[0][1] * a[1][0] % MOD);
        c[0][1] = (a[0][0] * a[0][1] % MOD) + (a[0][1] * a[1][1] % MOD);
        c[1][0] = (a[1][0] * a[0][0] % MOD) + (a[1][1] * a[1][0] % MOD);
        c[1][1] = (a[1][0] * a[0][1] % MOD) + (a[1][1] * a[1][1] % MOD);
        a[0][0] = c[0][0] % MOD;
        a[0][1] = c[0][1] % MOD;
        a[1][0] = c[1][0] % MOD;
        a[1][1] = c[1][1] % MOD;
        x>>= 1;
    }
}
int main() {
    cin >> n;
    if(n==0){
        cout<<1<<endl;
        return 0;
    }
    n--;
    qpow(n);
    cout<<(b[1][0]+b[1][1]*3)% MOD<<endl;
    return 0;
}