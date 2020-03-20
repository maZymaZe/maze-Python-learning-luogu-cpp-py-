#include<cstdio>
void func(long long bg,long long n,long long m){
    long long len=(n-bg+1);
    if(len==1){
        printf("%lld ",bg);
    }
    else if(len==2){
        if(m==1)printf("%lld %lld ",bg+1,bg);
        if(m==0)printf("%lld %lld ",bg,bg+1);
    }
    else if(m>(len-2)*(len-1)/2){
        long long head=m-(len-2)*(len-1)/2+bg;
        printf("%lld ",head);
        for(long long i=n;i>=bg;i--){
            if(i!=head)printf("%lld ",i);
        }
    }
    else {
        printf("%lld ",bg);
        func(bg+1,n,m);
    }
}
int main(){
    long long n,m;
    scanf("%lld%lld",&n,&m);
    func(1,n,m);
    return 0;
}