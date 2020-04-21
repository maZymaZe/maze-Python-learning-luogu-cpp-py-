#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[50004],c[50004],ans,ma;
int main(){
    scanf("%d%d",&n,&m);
    a[n+1]=2000000000;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    int r=2;
    for(int i=1;i<=n;i++){
        while(a[r]-a[i]<=m)r++;
        c[r]=max(r-i,c[r]);
        ma=max(c[i],ma);
        ans=max(ans,ma+r-i);
    }
    printf("%d",ans);
    return 0;
}