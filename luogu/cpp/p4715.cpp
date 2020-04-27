#include<cstdio>
int n,a[(1<<7)+4];
int f(int l,int r){
    int m=-1,s=l;
    for(int i=l;i<=r;i++){
        if(a[i]>m)m=a[i],s=i;
    }
    return s;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=(1<<n);i++)scanf("%d",&a[i]);
    int c=f(1,(1<<n));
    if(c<=(1<<(n-1)))printf("%d",f((1<<(n-1))+1,1<<n));
    else printf("%d",f(1,(1<<(n-1))));
    return 0;
}
