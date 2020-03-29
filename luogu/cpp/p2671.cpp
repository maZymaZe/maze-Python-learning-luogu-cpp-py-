#include<cstdio>
long long n,m,ans=0, c[100006],v[100006];
long long s12[100006][2],s1[100006][2],s2[100006][2],gs[100006][2];
int main(){
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%lld",&v[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%lld",&c[i]);
        gs[c[i]][i%2]++;
        if(gs[c[i]][i%2]>1){
            ans=(ans+s1[c[i]][i%2]*v[i])%10007;
            ans=(ans+s2[c[i]][i%2]*(i+1))%10007;
            ans=(ans+s12[c[i]][i%2])%10007;
            ans=(ans+(gs[c[i]][i%2]-1)*(i+1)%10007*v[i])%10007;
        }
            s1[c[i]][i%2]=(s1[c[i]][i%2]+(i+1))%10007;
            s2[c[i]][i%2]=(s2[c[i]][i%2]+v[i])%10007;
            s12[c[i]][i%2]=(s12[c[i]][i%2]+v[i]*(i+1))%10007;
        
    }
    printf("%lld",ans);
    return 0;
}