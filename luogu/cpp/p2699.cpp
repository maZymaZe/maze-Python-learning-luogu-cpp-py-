#include<cstdio>
long long l,r,w,m=1;
bool flag=false;
int main(){
    scanf("%lld%lld%lld",&l,&r,&w);
    if(w==1){
        printf(l==1?"1":"-1");
        return 0;
    }
    while(m<=r/w&&m>0){
        if(m>=l){
            printf("%lld ",m);
            flag=true;
        }
        m*=w;
    }
    if(m>0&&m<=r&&m>=l)printf("%lld ",m),flag=true;
    if(!flag)printf("-1");
    return 0;
}