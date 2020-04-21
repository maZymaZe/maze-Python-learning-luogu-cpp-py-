#include<cstdio>
long long l,r,nisp[70000],p[20000],pp=0,cnt,f,v[1000006];
int main(){
    scanf("%lld%lld",&l,&r);
    for(long long i=2;i<=(1<<16);i++){
        if(nisp[i]==0){
            pp++;p[pp]=i;
            for(long long j=2*i;j<=(1<<16);j+=i){
                nisp[j]=1;
            }
        }
    }
    for(long long k=1;k<=pp;k++){
        for(long long i=l/p[k]*p[k];i<=r;i+=p[k]){
            if(i<l)i+=p[k];
            if(i!=p[k]){
                v[i-l+1]=1;
            }
        }
    }
    for(long long i=l;i<=r;i++){
        if(v[i-l+1]==0)cnt++;
    }
    printf("%lld",cnt);
    return 0;
}