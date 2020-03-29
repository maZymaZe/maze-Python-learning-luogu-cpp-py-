#include<cstdio>
int l,r,p,f[100006],s[100006],u[100006],t=0;
int fx(int x){
    if(f[x]==x)return x;
    else return f[x]=fx(f[x]);
}
int main(){
    scanf("%d%d%d",&l,&r,&p);
    for(int i=1;i<=r;i++){
        f[i]=i;
    }
    for(int i=2;i<=r;i++){
        if(s[i]==0){
            for(int j=i*2;j<=r;j+=i){
                s[j]=2;
                if(j>=l&&i>=p){
                   f[fx(j)]=fx(i);
                }
            }
        }
    }
    
    for(int i=l;i<=r;i++)u[fx(i)]++;
    for(int i=1;i<=r;i++)if(u[i])t++;
    printf("%d",t);
    return 0;
}