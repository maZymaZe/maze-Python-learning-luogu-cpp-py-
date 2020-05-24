#include <cmath>
#include <cstdio>
#define MAX 3000006
const double pi = acos(-1.0);
inline int read() {
    char c = getchar();
    int x = 0, f = 1;
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * f;
}
struct complex {
    double x, y;
    complex(double xx = 0, double yy = 0) { x = xx, y = yy; };
} a[MAX], b[MAX];
complex operator+(const complex& a, const complex& b) {
    return complex(a.x + b.x, a.y + b.y);
}
complex operator-(const complex& a, const complex& b) {
    return complex(a.x - b.x, a.y - b.y);
}
complex operator*(const complex& a, const complex& b) {
    return complex(a.x * b.x - a.y * b.y, a.y * b.x + a.x * b.y);
}
int N, M, l, r[MAX], limit = 1;
void fft(complex* A, int type) {
    for (int i = 0; i < limit; i++) {
        if (i < r[i]) {
            complex t = A[i];
            A[i] = A[r[i]];
            A[r[i]] = t;
        }
    }
    for (int mid = 1; mid < limit; mid <<= 1) {
        complex Wn(cos(pi / mid), type * sin(pi / mid));
        for (int R = mid << 1, j = 0; j < limit; j += R) {
            complex w(1, 0);
            for (int k = 0; k < mid; k++, w = w * Wn)

            {
                complex x = A[j + k], y = w * A[j + mid + k];
                A[j + k] = x + y;
                A[j + mid + k] = x - y;
            }
        }
    }
}
int main() {
    N = read();
    M = read();
    for (int i = 0; i <= N; i++) {
        a[i].x = read();
    }
    for (int i = 0; i <= M; i++) {
        b[i].x = read();
    }
    while (limit <= N + M) {
        l++, limit <<= 1;
    }
    for (int i = 0; i < limit; i++) {
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
    }
    fft(a, 1);
    fft(b, 1);
    for (int i = 0; i <= limit; i++) a[i] = a[i] * b[i];
    fft(a, -1);
    for (int i = 0; i <= N + M; i++) {
        printf("%d ", (int)(a[i].x / limit + 0.5));
    }
    return 0;
}