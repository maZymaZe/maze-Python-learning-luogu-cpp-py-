#include<cstdio>
int main(){
    int n;
    long long x,y;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&x,&y);
        if((x+y)%2==0)
        printf("%lld\n",(long long)(x+y)/2%9*(y-x+1)%9);
        else
        printf("%lld\n",(long long)(y-x+1)/2%9*(x+y)%9);
        
    }
    return 0;
}