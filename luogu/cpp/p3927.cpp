#include<cstdio>
long long n,k,a[200003],ans,cnt=0,c[200003];
int main() {
    scanf("%lld%lld",&n,&k);
    for(long long i=2;i*i<=k;i++){
        if(k%i==0){
            a[++cnt] =i;
            c[cnt]=0;
            while(k%i==0){
                ++c[cnt];
                k/=i;
            }
        }
    }
    if(k>1){
        a[++cnt] =k;
        c[cnt]=1;
    }
    ans=20000000000000;
    for(int i=1;i<=cnt;i++){
        long long t=0,now=n;
        while(now){
            t+=(now/=a[i]);
        }
        t/=c[i];
        if(t<ans)ans=t;
    }
    printf("%lld\n",ans);
    return 0;
}