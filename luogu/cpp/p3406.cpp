#include<cstdio>
long long ans=0;
int ct=0,pre,now,n,m,cnt[100008],a,b,c;
int main(){
    scanf("%d%d%d",&n,&m,&now);
    for(int i=1;i<m;i++){
        pre=now;
        scanf("%d",&now);
        if(now>pre){
            cnt[pre]++;
            cnt[now]--;
        }
        else{
            cnt[now]++;
            cnt[pre]--;
        }
    }
    for(int i=1;i<n;i++){
        scanf("%d%d%d",&a,&b,&c);
        ct+=cnt[i];
        if((long long)(a-b)*ct<c)
            ans+=(long long)a*ct;
        else ans+=(long long)b*ct+c;
    }
    printf("%lld",ans);
    return 0;
}