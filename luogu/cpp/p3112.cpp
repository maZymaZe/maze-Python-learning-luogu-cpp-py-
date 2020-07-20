#include <cstdio>
#include<algorithm>
using namespace std;
struct cow{
    int h,w,s;
    bool operator <(const cow& x){
        return w+s>x.w+x.s;
    }
}c[25];
int main(){
    long long sum=0,ans=-1;
    int n,height;
    scanf("%d%d",&n,&height);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&c[i].h,&c[i].w,&c[i].s);
        sum+=c[i].h;
    }
    if(sum<height){
        printf("Mark is too tall\n");
        return 0;
    }
    sum=0;
    sort(c+1,c+1+n);
    int st=(1<<n)-1;
    for(int i=0;i<=st;i++){
        int t=i,j=1,z=0x3f3f3f3f;
        sum=0;
        while(t){
            if(t&1){
                sum+=c[j].h;
                z=min(z-c[j].w,c[j].s);
                if(z<0)break;
            }
            j++;
            t>>=1;
        }
        if(t!=0||sum<height)continue;
        if(z>ans)ans=z;
    }
    if(ans==-1)printf("Mark is too tall\n");
    else printf("%lld\n",ans);
    return 0;
}