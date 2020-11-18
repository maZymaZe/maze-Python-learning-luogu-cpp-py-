#include<cstring>
#include<cstdio>
const int NMAX=1e6+4;
const int P=131;
const long long MOD=19260817;
char s[NMAX];
int ans[NMAX],cnt,l,r,n;
long long x,y,p[NMAX],sum[NMAX];
void myhash(){
    p[0]=1;
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]*P%MOD;
        sum[i]=(sum[i-1]*P%MOD+s[i]-'a'+1);
    }
}
long long hs(int l,int r){
    return (sum[r]-sum[l-1]*p[r-l+1]%MOD+MOD)%MOD;
}
int main(){
    scanf("%d%s",&n,s+1);
    myhash();
    cnt=(n+1)>>1;
    if(n&1)ans[cnt]=-1,l=r=cnt;
    else{
        l=n>>1,r=l+1;
        if(s[l]==s[r])ans[cnt]=1;
        else ans[cnt]=-1;
    }
    for(int i=cnt-1;i>=1;i--){
        l--,r++;
        for(int j=ans[i+1]+2;j>=-1;j-=2){
            x=hs(l,l+j-1),y=hs(r-j+1,r);
            if(x==y||j==-1){
                ans[i]=j;
                break;
            }
        }
    }
    for(int i=1;i<=cnt;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}