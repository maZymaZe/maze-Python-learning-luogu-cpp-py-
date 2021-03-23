#include<cstdio>
#include<algorithm>
using namespace std;
const int NMAX=4e5+ 10;
int a[NMAX],b[NMAX],ans,n;
bool calc(int l,int r){
    if(l>r)return false;
    long long ret=0; 
    for(int i=n,il=1,ir=1;i;i--){
        while(il<=n&&b[i]+b[il]<l)il++;
        while(ir<=n&&b[i]+b[ir]<=r)++ir;
        ret+=(ir-il)-(il<=i&&i<ir);
    }
    return (ret>>1)&1;
}
int sv(int k){
    for(int i=1;i<=n;i++){
        b[i]=a[i]&((1<<(k+1))-1);        
    }
    sort(b+1, b+1+n); 
    return calc(1<<k,(1<<(k+1))-1)^calc(3<<k,(1<<(k+2))-2);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){scanf("%d",&a[i]);}
    for(int i=0;i<26;i++)ans|=(sv(i)<<i);
    printf("%d\n",ans);
    return 0;
}