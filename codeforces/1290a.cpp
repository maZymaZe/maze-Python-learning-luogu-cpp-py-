#include<cstdio>
#include<algorithm>
using namespace std;
int T,n,m,k,a[4000];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        k=min(k,m-1);
        int ans=0;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=0;i<=k;i++){
            int s=1e9;
            for(int j=0;j<=m-k-1;j++){
                s=min(s,max(a[i+j+1],a[n+i-m+j+1]));
            }
            ans=max(ans,s);
        }
        printf("%d\n",ans);
    }
    return 0;
}