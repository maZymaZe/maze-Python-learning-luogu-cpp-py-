#include<algorithm>
#include<cstdio>
using namespace std;
int x[14],y[14],a[14],n,ans;
bool work(){
    int lx=0,ly=0;
    for(int i=0;i<n;i++){
        int p=a[i];
        int tx=x[p],ty=y[p];
        int nx=x[a[i+1]],ny=y[a[i+1]];
        if(((lx==tx)||(ly==ty))==0)return 0;
        if(((nx==tx)||(ny==ty))==0)return 0;
        int x1=tx-lx,y1=ty-ly;
        int x2=nx-tx,y2=ny-ty;
        if((x1*x2+y1*y2)>0)return 0;
        lx=tx,ly=ty;
    }
    return 1;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&x[i],&y[i]);
        a[i] = i;
    }    
    a[n]=n;
    do{
        ans+=work();
    }while(next_permutation(a,a+n));
    printf("%d\n",ans);
    return 0;
}
