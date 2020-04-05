#include<algorithm>
#include<cstdio>
using namespace std;
int n,c,a[200002];
long long cnt=0,p,q;
int main(){
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    int head=1,tail=2;
    while(head<=n&&tail<=n){
        if(a[tail]-a[head]>c)head++;
        else if(a[tail]-a[head]==c)
        {
           p=1;q=1;
           while(head<n&&a[head]==a[head+1])head++,p++;
           while(tail<n&&a[tail]==a[tail+1])tail++,q++;
           head++;
           cnt+=p*q;
        }
        else tail++;
        
        if(head==tail)tail++;
    }
    printf("%lld",cnt);
    return 0;
}
