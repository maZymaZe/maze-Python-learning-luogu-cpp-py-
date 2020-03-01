#include<cstdio>
int a[100005],l,r,n,m,mid;
int ck(int x){
    int zs=1,ns=x;
    for(int i=1;i<=n;i++){
        if(a[i]>x)return 0;
        if(ns<a[i]){
            zs++;
            ns=x-a[i];
        }
        else ns-=a[i];
        if(zs>m)return 0;
    }
    return 1;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    l=0,r=1000000000;
    while (r-l>1)
    {
        mid=(l+r)/2;
        if(ck(mid)==1)r=mid;
        else l=mid;
    }
    printf("%d",r);
    return 0;   
}