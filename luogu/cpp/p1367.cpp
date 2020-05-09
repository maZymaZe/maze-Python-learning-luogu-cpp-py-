#include<cstdio>
#include<algorithm>
using namespace std;
int n,t,x[100006];
struct ant{
    int p,d,s;
}a[100006];
int cmp1(const ant&a,const ant&b){
    return a.p < b.p;
}
int main(){
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].p,&a[i].d);        
        a[i].s=i;
    }
    sort(a+1,a+1+n,cmp1);
    for(int i=1;i<=n;i++){
         a[i].p+=a[i].d*t;
         x[a[i].s]=i;
    }
    sort(a+1,a+1+n,cmp1);
    for(int i= 1; i <= n; i++){
        if(i>1&&a[i-1].p==a[i].p)a[i].d=0;
        if(i<n-1&&a[i+1].p==a[i].p)a[i].d=0;   
    }

    for(int i=1;i<=n;i++)printf("%d %d\n",a[x[i]].p,a[x[i]].d);
    return 0;
}