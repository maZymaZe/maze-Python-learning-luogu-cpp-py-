#include<cstdio>
int n,k,a[503],ans=0;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=2;i<=n;i++){
        int t=a[i]+a[i-1];
        if(t<k)a[i]+=k-t,
        ans+=k-t;
    }
    printf("%d\n",ans);
    for(int i=1;i<=n;i++)printf("%d ",a[i]);
    return 0;
}