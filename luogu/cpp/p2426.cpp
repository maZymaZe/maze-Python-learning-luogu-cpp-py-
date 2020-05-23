#include<cstdio>
inline int abs(int x){return (x>0)?x:-x;}
inline int max(int a,int b){return a>b?a:b;}

int n,a[102],ans[102]={0};
int f(int l,int r){
    if(l==r)return a[l];
    else return (r-l+1)*abs(a[l]-a[r]);
}
int main(){
    scanf("%d",&n);
    for(int i=0; i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        ans[i]=f(0,i);
        for(int j=0;j<i;j++)
        ans[i]=max(ans[i],ans[j]+f(j+1,i));
    }
    printf("%d",ans[n-1]);
    return 0;
}