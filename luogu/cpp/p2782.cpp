#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int nc=2e5+10;

struct ct{
    int a,b;
}c[nc];
bool cmp(const ct& p,const ct& q){
    return p.a<q.a||(p.a==q.a&&p.b<q.b);
}
int main(){
    int n;
    vector<int> v;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&c[i].a,&c[i].b);
    }
    sort(c+1,c+1+n,cmp);
    for(int i=1;i<=n;i++){
        if(v.empty()){
            v.push_back(c[i].b);
        }
        else{
            if(c[i].b>v.back())v.push_back(c[i].b);
            else{
                int w=lower_bound(v.begin(),v.end(),c[i].b)-v.begin();
                v[w]=c[i].b;
            }
        }
    }
    printf("%d\n",v.size());
    return 0;
}