#include <cmath>
#include <cstdio>
double a, v, l, d, w, t;
double mv(double v1, double v2, double ac, double len) {
    double ut = 0;
    double s = (v2 * v2 - v1 * v1) / 2 / ac;
    if (s >= len)
        ut = (-v1 + sqrt(v1 * v1 + 2 * ac * len)) / ac;
    else {
        double t1 = (v2 - v1) / ac;
        double t2 = (len - s) / v2;
        ut = t1 + t2;
    }
    return ut;
}
int main() {
    scanf("%lf%lf%lf%lf%lf", &a, &v, &l, &d, &w);
    double s = v * v / 2 / a;
    if (w >= v) {
        t = mv(0, v, a, l);
    } else {
        double s1 = w * w / a / 2;
        if (s1 >= d)
            t = mv(0, v, a, l);
        else {
            double t11 = sqrt((2 * a * d + w * w) / 2 / a / a);
            double t1;
            if (t11 * a <= v)
                t1 = 2 * t11 - w / a;
            else {
                double s11 = v * v / 2 / a;
                double s12 = (v * v - w * w) / a / 2;
                t1 = v / a + (v - w) / a + (d - s11 - s12) / v;
            }
            double t2 = mv(w, v, a, l - d);
            t = t1 + t2;
        }
    }
    printf("%.12lf\n", t);
    return 0;
}