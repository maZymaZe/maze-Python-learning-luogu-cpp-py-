#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
const int NMAX=104;
double a[NMAX][NMAX];
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n+1;j++)scanf("%lf",&a[i][j]);
    }
    for(int i=1;i<=n;i++){
        int ma=i;
        for(int j=i+1;j<=n;j++){
            if(fabs(a[j][i])>fabs(a[ma][i]))ma=j;
        }
        for(int j=1;j<=n+1;j++)swap(a[i][j],a[ma][j]);
        if(!a[i][i]){
            printf("No Solution");
            return 0;
        }
        for(int j=1;j<=n;j++){
            if(j!=i){
                double tmp=a[j][i]/a[i][i];
                for(int k=i+1;k<=n+1;k++){
                    a[j][k]-=a[i][k]*tmp;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%.2lf\n",a[i][n+1]/a[i][i]);
    }
    return 0;
}