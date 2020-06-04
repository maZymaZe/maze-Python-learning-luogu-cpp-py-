#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct gd{
    int x,y;
    int t,v;
    double p;
    bool operator <(const gd& tmp){
        if(p+1e-6 < tmp.p)return 1;
        else if(p-tmp.p>-1e-6&&p-tmp.p<1e-6){
            return y<tmp.y;
        }
        return 0;
    }
}g[201];
int n,T,dp[40005],cd=0;
struct ggd{
    int t,v;
};
vector<vector<ggd> > d;
int main(){
    scanf("%d%d",&n,&T);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d%d",&g[i].x,&g[i].y,&g[i].t,&g[i].v);
        g[i].p=1.0*g[i].x/g[i].y;
    }
    sort(g+1,g+1+n);
    double pre=-99999999;
    vector<ggd> tp;
    for(int i=1;i<=n;i++){
        if(g[i].p-pre<1e-6&&g[i].p-pre>-1e-6){
            if(tp.empty()){
                tp.push_back({g[i].t,g[i].v});
            }
            else{
                tp.push_back({tp[tp.size()-1].t+g[i].t,tp[tp.size()-1].v+g[i].v});
            }
        }
        else{
            d.push_back(tp);
            tp.clear();
            tp.push_back({g[i].t,g[i].v});
            pre=g[i].p;
        }
    }
    d.push_back(tp);
    cd=d.size();
    for(int i=0;i<cd;i++){
        for(int j=T;j>=0;j--){
            for(int k=d[i].size()-1;k>=0;k--){
                if(j>=d[i][k].t){
                    dp[j]=max(dp[j],dp[j-d[i][k].t]+d[i][k].v);
                }
            }
        }
    }
    printf("%d",dp[T]);
    return 0;
}
