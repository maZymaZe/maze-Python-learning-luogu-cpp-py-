#include <algorithm>
#include <cstdio>
#include<cmath>
using namespace std;
const int NMAX = 2000007;
const double Pi= acos(-1.0);
long long n, px, s[NMAX], f[NMAX], t, lim = 1, r[NMAX], l;
struct Complex {
    double real, imaginary;
    Complex(double x = 0, double y = 0) { real = x, imaginary = y; }
} a[NMAX], b[NMAX];
Complex operator*(Complex x, Complex y) {
    return Complex(x.real * y.real - x.imaginary * y.imaginary,
                   x.real * y.imaginary + x.imaginary * y.real);
}
Complex operator+(Complex x, Complex y) {
    return Complex(x.real + y.real, x.imaginary + y.imaginary);
}
Complex operator-(Complex x, Complex y) {
    return Complex(x.real - y.real, x.imaginary - y.imaginary);
}
void FFT(Complex *A,double flag){
    for(int i=0;i<lim;i++){
        if(i<r[i])swap(A[i],A[r[i]]);
    }
    for(int mid=1;mid<lim;mid<<=1){
        Complex Wn(cos(Pi/ mid),flag*sin(Pi/ mid));
        for(int j=0;j<lim;j+=(mid<<1)){
            Complex w(1, 0);
            for(int k=0;k<mid;k++, w = w * Wn){
                Complex nx=A[j+k],ny=w*A[j+k+mid];
                A[j+k]=nx+ny,A[j+k+mid]=nx-ny;
            }
        }
    }
}
long long get0(){
    long long p=0,res=0;
    for(int i=1;i<=n;i++){
        if(s[i]!=s[i-1])p=i;
        res+=i-p;
    }
    return res;
} 
int main() {
    scanf("%lld%lld", &n, &px);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &t);
        if (t < px)
            s[i] = s[i - 1] + 1;
        else
            s[i] = s[i - 1];
        f[s[i]]++;
    }
    f[0]++;
    while (lim <= n + n)
        lim <<= 1, l++;
    for (int i = 0; i < lim; i++) {
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
    }
    for(int i=0;i<=n;i++)a[i].real=f[i],b[i].real=f[n-i];
    FFT(a,1);FFT(b,1);
    for(int i=0;i<=lim;i++)a[i]=a[i]*b[i];
    FFT(a,-1);
    printf("%lld ",get0());
    for(int i=n-1;i>=0;i--)printf("%lld ",(long long)(a[i].real/lim+0.5));
    return 0;
}