#include<cstdio>
int ls[2000],n;
char jg(int l,int r){
    int f=ls[l];
    for(int i=l;i<=r;i++){
        if(ls[i]!=f){
            f=2;
            break;
        }
    }
    if(f==0)return 'B';
    if(f==1)return 'I';
    return 'F';
}
void dfs(int l ,int r,int p){
    if(p>0){
        dfs(l,l+(1<<(p-1))-1,p-1);
        dfs(l+(1<<(p-1)),r,p-1);
    }
    printf("%c",jg(l,r));
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=(1<<n);i++){
        scanf("%1d",&ls[i]);
    }
    dfs(1,1<<n,n);
    return 0;
}