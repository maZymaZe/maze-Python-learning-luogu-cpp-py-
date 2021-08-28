#include<cstdio>
#include<algorithm>
using namespace std;
struct ANS{
    int a,b;
    bool operator<(const ANS& x){ 
        return b<x.b||(b==x.b && a < x.a);
    }
}ans[10010];
const int MSZ=250*250*2+10;
int vis[MSZ]= {0},n,m,p=0;
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<=m;i++){
        for(int j=0;j<=m;j++){
            vis[i*i+j*j]=1;
        }
    }
    int maxs=2*m*m,maxi;
    for(int i=0;i<=maxs;i++){
        if(vis[i]){
            for(int j=i+1;j<=maxs;j++){
                if(vis[j]){
                    int d=j-i;
                    maxi=i+(n-1)*d;
                    if(maxi>maxs)break;
                    bool f=true;
                    for(int k=i+d;k<=maxi;k+=d){
                        if(!vis[k]){
                            f=false;
                            break;
                        }
                    }
                    if(f){
                        p++;
                        ans[p]={i,d};
                    }
                }
            }
        }
    }
    if(!p){
        printf("NONE\n");
    }
    else{
        sort(ans+1,ans+p+1);
        for(int i=1;i<=p;i++){
            printf("%d %d\n",ans[i].a,ans[i].b);
        }
    }
    return 0;
}