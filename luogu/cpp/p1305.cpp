#include<cstdio>
struct note
{
    int l,r;
}nt[300];
int n,o;
char t[4];
void dfs(int x){
    printf("%c",x);
    if(nt[x].l)dfs(nt[x].l);
    if(nt[x].r)dfs(nt[x].r);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",t);
        if(i==1)o=(int)(t[0]);
        if(t[1]!='*')nt[t[0]].l=t[1];
        else nt[t[0]].l=0;
        if(t[2]!='*')nt[t[0]].r=t[2];
        else nt[t[0]].r=0;
    }
    dfs(o);
    return 0;
}
