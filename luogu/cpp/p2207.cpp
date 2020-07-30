#include<cstdio>
#include<algorithm>
using namespace std;
struct pr{
    int l,r;
    bool operator<(const pr& x){ 
        return l < x.l||(l==x.l && r < x.r);
    }
}p[1004];
int n,k,ans=1;
int main(){
    scanf("%d%d", &n,&k);
    for(int i=0;i<k; i++){
        scanf("%d%d",&p[i].l,&p[i].r);
        if(p[i].l>p[i].r){
            swap(p[i].l,p[i].r);
        }
    }
    sort(p,p+k);
    int ll=p[0].l,rr=p[0].r;
    for(int i=1; i<k; i++){
        if(p[i].l<rr){
            ll=max(ll,p[i].l);
            rr=min(rr,p[i].r);
        }
        else{
            ll=p[i].l;
            rr=p[i].r;
            ans++;
        }
    }
    if(k)ans++;
    printf("%d\n",ans);
    return 0;
}