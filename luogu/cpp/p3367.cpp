#include<cstdio>
int n,m,f[10004]={0},a,b,c;
int fd(int x){
    if(f[x]==x)return x;
    else return f[x]=fd(f[x]);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a,&b,&c);
        if(a==1){
            f[fd(b)]=fd(c);
        }
        else{
            if(fd(b)==fd(c))printf("Y\n");
            else printf("N\n");
        }
    }
    return 0;
}