#include<algorithm>
#include<cstdio>
using std::sort;
int T,a[60],b[60],x,n;
int main() {
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&x);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
        }
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        int flag=1;
        for(int i=1;i<=n;i++){
            if(a[i]+b[n-i+1]>x)flag=0;
        }
        printf(flag?"Yes\n":"No\n");
    }
    return 0;
}