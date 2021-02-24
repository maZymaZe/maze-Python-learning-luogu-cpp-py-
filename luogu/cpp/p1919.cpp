#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
const int NMAX = 3e6 + 10;
const double Pi = acos(-1.0);
char s1[NMAX], s2[NMAX];
int N, M, K, l1, l2, res = 0, ans[NMAX], AA, BB, Lim = 1, L = 0, R[NMAX];
struct Complex {
    double real, imaginary;
    Complex(double x = 0, double y = 0) { real = x, imaginary = y; }
} A[NMAX], B[NMAX];
Complex operator*(Complex x, Complex y) {
    return Complex(x.real * y.real - x.imaginary * y.imaginary,
                   x.real * y.imaginary + y.real * x.imaginary);
}
Complex operator+(Complex x, Complex y) {
    return Complex(x.real + y.real, x.imaginary + y.imaginary);
}
Complex operator-(Complex x, Complex y) {
    return Complex(x.real - y.real, x.imaginary - y.imaginary);
}
inline void FFT(Complex* J, double flag) {
    for (int i = 0; i < Lim; i++) {
        if (i < R[i])
            swap(J[i], J[R[i]]);
    }
    for (int j = 1; j < Lim; j <<= 1) {  // MidPoint for merging
        Complex Wn(cos((double)Pi / j), flag * sin((double)Pi / j));
        for (int k = 0; k < Lim; k += (j << 1)) {
            Complex w(1, 0);
            for (int l = 0; l < j; l++, w = w * Wn) {
                Complex Nx = J[k + l], Ny = w * J[k + j + l];
                J[k + l] = Nx + Ny;
                J[k + l + j] = Nx - Ny;
            }
        }
    }
}
int main() {
    scanf("%s%s", s1, s2);
    l1 = strlen(s1), l2 = strlen(s2);
    N = max(l1, l2);
    for (int i = l1 - 1; i >= 0; i--) {
        A[AA++].real = s1[i] - '0';
    }
    for (int i = l2 - 1; i >= 0; i--) {
        B[BB++].real = s2[i] - '0';
    }
    while (Lim < N + N)
        Lim <<= 1, L++;
    for (int i = 0; i <= Lim; i++) {
        R[i] = (R[i >> 1] >> 1) | ((i & 1) << (L - 1));
    }
    FFT(A, 1), FFT(B, 1);
    for (int i = 0; i <= Lim; i++) {
        A[i] = A[i] * B[i];
    }
    FFT(A, -1);
    int tot = 0;
    for (int i = 0; i <= Lim; i++) {
        ans[i] += (int)(A[i].real / Lim + 0.5);
        if (ans[i] >= 10) {
            ans[i + 1] += ans[i] / 10, ans[i] %= 10, Lim += (i == Lim);
        }
    }
    while (!ans[Lim] && Lim >= 1)
        Lim--;
    Lim++;
    while (--Lim >= 0)
        printf("%d", ans[Lim]);
    return 0;
}
