#include<cstdio>
#include<cstring>
int abs(int x) { return x < 0?-x:x;}
int dp[20][20][2][2],aa,bb,s[20];
int dfs(int len,int pre,bool lim,bool zero){
    int& t=dp[len][pre][lim][zero];
    if(~t)return t;
    if(!len)return t=1;
    t=0;
    int mx=lim?s[len]:9;
    int mn=zero?1:0;
    for(int i=mn;i<=mx; i++){
        if(abs(i-pre)<2)continue;
        t+=dfs(len-1,i,lim&&(i==mx),0);
    }
    return t;
}

int query(int x){
    if(x<10)return x;
    memset(dp,-1,sizeof(dp));
    int ans=0,len=0;
    do{
        s[++len]=x%10;
        x/=10;
    }while(x);
    ans+=dfs(len,11,1,1);
    for(int i=len-1;i>=1;i--){
        ans+=dfs(i,11,0,1);
    }
    return ans;

}
int main(){
    scanf("%d%d",&aa,&bb);
    printf("%d",query(bb)-query(aa-1));
    return 0;
}