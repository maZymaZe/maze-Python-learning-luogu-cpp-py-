#include<cstdio>
#include<algorithm>
using namespace std;
struct spread{
    long long l,r,k;
}s[1003];
long long n,m,cnt=0,op,t1,t2,t3,ans=0;
int main(){
    scanf("%lld%lld", &n,&m);
    for(int i=0;i<m; i++){
        scanf("%lld", &op);
        if(op == 1){
            cnt++;
            scanf("%lld%lld%lld",&s[cnt].l,&s[cnt].r,&s[cnt].k);
        }else{
            scanf("%lld%lld",&t1,&t2);
            ans=0;
            for(int j=1;j<=cnt;j++){
                if(s[j].l<=t2&&s[j].r>=t1){
                    ans+=(min(t2,s[j].r)-max(t1,s[j].l)+1)*s[j].k;
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}