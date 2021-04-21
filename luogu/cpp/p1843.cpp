#include<cstdio>
const int NMAX=5e5 + 10;
int w[NMAX],n,a,b;
bool ck(int x){
    int u=0;
    for(int i=1;i<=n;i++){
        if(a*x<w[i]){
            u+=(w[i]-a*x+b-1)/b;
            if(u>x)return false;
        }
    }
    return true;
}
int main(){
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
    }
    int l=1,r=NMAX,mid;
    while(l<r){
        mid=l+((r-l)>>1);
        if(ck(mid))r=mid;
        else l=mid+1;
    }
    printf("%d\n",l);
    return 0;
}