#include <cmath>
#include <cstdio>
const double PI = acos(-1.0), EPS = 1e-3;
double x[3], y[3];
double len[3], a[3];
double glen(int p, int q) {
    return sqrt((x[p] - x[q]) * (x[p] - x[q]) + (y[p] - y[q]) * (y[p] - y[q]));
}
double fgcd(double p, double q) {
    if (fabs(p) < EPS)
        return q;
    if (fabs(q) < EPS)
        return p;
    return fgcd(q, fmod(p, q));
}
int main() {
    double t = 0, A, r;
    for (int i = 0; i < 3; i++) {
        scanf("%lf%lf", &x[i], &y[i]);
    }
    for (int i = 0; i < 3; i++) {
        len[i] = glen(i, (i + 1) % 3);
        t += len[i];
    }
    t /= 2;
    A = sqrt(t * (t - len[0]) * (t - len[1]) * (t - len[2]));
    r = len[0] * len[1] * len[2] / 4 / A;
    for (int i = 0; i < 2; i++) {
        a[i] = acos(1 - len[i] * len[i] / 2 / r / r);
    }
    a[2] = 2 * PI - a[0] - a[1] - a[2];
    t = fgcd(a[0], fgcd(a[1], a[2]));
    printf("%.6lf", PI * r * r * sin(t) / t);
    return 0;
}