#include<cstdio>
#include<algorithm>
using namespace std;
long long cnt;
int n,f[40004]={0};
int main(){
    scanf("%d",&n);
    if(n==1)printf("0\n");
    else {
        cnt=(n-1)*(n-1);
        n--;
        for(int i=n;i>=2;i--){
            f[i]=(n/i)*(n/i);
            for(int j=2*i;j<=n;j+=i)f[i]-=f[j];
            cnt-=f[i];
        }
        printf("%lld\n",cnt+2);
    }
    return 0;
}