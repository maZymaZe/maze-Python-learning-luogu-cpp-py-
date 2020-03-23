#include<cstdio>
int main(){
    int n,t=0,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&t);
        ans^=t;
    }
    printf("%d",ans);
    return 0;
}