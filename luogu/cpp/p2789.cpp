#include<cstdio>
int n,ls[30],t[320],ans=0;
void dfs(int m,int l,int x){
    if(m==0){
        int tot=0,k=n;
        for(int i=0;i<l;i++){
            tot+=k-ls[i];
            k-=ls[i];
        }
        t[tot]++;
    }
    else{
        int s;
        if(x<m)s=x;
        else s=m;
        for(int i=s;i>=1;i--){
            ls[l]=i;
            dfs(m-i,l+1,i);
            ls[l]=0;
        }
    }
}
int main(){
    scanf("%d",&n);
    dfs(n,0,n);
    for(int i=0;i<=310;i++){
        if(t[i])ans++;
    }
    printf("%d",ans);
    return 0;
}