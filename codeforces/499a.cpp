#include<cstdio>
int n,x,pe,b,e,ans=0;
int main(){
    scanf("%d%d",&n,&x);
    pe=1;
    for(int i=0;i<n;i++){
        scanf("%d%d",&b,&e);
        ans+=e-b+1;
        ans+=(b-pe)%x;
        pe=e+1;
    }
    printf("%d",ans);
    return 0;
}