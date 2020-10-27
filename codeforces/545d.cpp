#include<cstdio>
#include<algorithm>
using namespace std;
const int NMAX = 1e5+10;
long long a[NMAX],tot=0;
int n,ans=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(tot<=a[i])ans++,tot+=a[i];
    }
    printf("%d\n",ans);
    return 0;
}