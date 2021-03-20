#include<cstdio>
long long T,n,a[100005],s[100005];
int main(){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        for(int i=1; i <= n; i++){
            scanf("%lld",&a[i]);
            s[i] = a[i]+s[i-1];
        }
        int mapos=n,mipos=0;
        long long ma=s[n],mi=0;
        for(int i=n-1;i>0;i--){
            if(s[i]>=ma){
                ma=s[i],mapos=i;
            }
        }
        for(int i=1;i<n;i++){
            if(s[i]<=mi){
                mi=s[i],mipos=i;
            }
        }
        if(ma-mi>=s[n]&&!(mapos==n&&mipos==0)){
            printf("NO\n");
        }
        else printf("YES\n");
    }
    return 0;
}