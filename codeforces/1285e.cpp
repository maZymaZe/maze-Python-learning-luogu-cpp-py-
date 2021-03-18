#include<cstdio>
#include<set>
#include<algorithm>
#include<utility>
#include<cstring>
using namespace std;
const int NMAX=2e5+10;
pair<int,int> a[NMAX*2];
int cnt[NMAX],x,y,n,T,m;
int main(){
    scanf("%d", &T);
    while(T--){
        m=0;
        memset(cnt,0,sizeof(cnt));
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
            scanf("%d%d",&x,&y);
            a[m++]={x,-i};
            a[m++]={y,i};
        }
        sort(a,a+m);
        set<int> se;
        int ans=0;
        for(int i=0;i<m; i++){
            int id=abs(a[i].second);
            if(a[i].second<0){
                if(se.size()==0)cnt[id]--;
                se.insert(id);
            }else{
                if(se.size()==1)cnt[id]--;
                se.erase(id);
            }
            if(se.empty())ans++;
            if(se.size()==1)cnt[*se.begin()]++;
        }
        int mx=-1;
        for(int i=1;i<=n;i++)mx=max(mx,cnt[i]);
        ans+=mx;
        printf("%d\n",ans);
    }
    return 0;
}