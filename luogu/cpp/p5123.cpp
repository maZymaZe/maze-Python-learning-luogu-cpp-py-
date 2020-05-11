#include<cstdio>
int n,a[1030],t;
int main(){
    long long ans = 0;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&t);
            if(i>j)ans+=(long long)1*t*(a[i]<a[j]?a[i]:a[j]);
        }
    }
    printf("%lld",ans);
    return 0;
}