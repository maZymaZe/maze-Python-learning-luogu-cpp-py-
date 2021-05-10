#include<cstdio>
#include<algorithm>
using namespace std;
const int NMAX =2e5+10;
int t,tot,n,T,ans,a[NMAX];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        n*=2;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+1+n);
        printf("%d\n",a[n/2+1]-a[n/2]);
    }
    return 0;
}