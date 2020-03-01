#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100005],l,r,n,m,mid;
int ck(int x){
    int nn=a[1],c=1;
    for(int i=2;i<=n;i++){
        if(a[i]-nn>=x)c++,nn=a[i];
        if(c==m)return 1;
    }
    return 0;    
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    l=0,r=1000000000;
    while (r-l>1)
    {
        mid=(l+r)/2;
        if(ck(mid)==0)r=mid;
        else l=mid;
    }
    printf("%d",l);
    return 0;   
}