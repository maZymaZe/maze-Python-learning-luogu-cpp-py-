#include<cstdio>
#include<cmath>
int gcd(int a,int b){
    if(a%b==0)return b;
    else return gcd(b,a%b);
}
long long ans;
int main(){
    int n,a1,a0,b1,b0;
    int x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
        ans=0;
        for(int i=1;i*i<=b1;i++){
            if(b1%i==0){
                x=b1/i;
                if(x%a1==0&&gcd(x/a1,a0/a1)==1&&gcd(b1/b0,b1/x)==1)ans++;
                if(x*x!=b1)
                if(i%a1==0&&gcd(i/a1,a0/a1)==1&&gcd(b1/b0,b1/i)==1)ans++;
            }
        }   
        printf("%lld\n",ans);
    }
    return 0;
}