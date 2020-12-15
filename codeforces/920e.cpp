#include<vector>
#include<cstdio>
#include<algorithm>
#include<unordered_set>
#include<set>
using namespace std;
const int NMAX=2e5+10;
vector<int> e[NMAX];
//unordered_set<int> s;
set<int> s;
int n,m,cnt[NMAX],t1,t2,c[NMAX],cc=0,q[NMAX],ql,qr;
void solve(int x){
    s.erase(x);c[x]=++cc;
    q[0]=x,qr=1,ql=0;
    while(ql<qr){
        int y=q[ql++];
        vector<int> tmp;
        for(int v:e[y])if(s.count(v))tmp.push_back(v);
        for(int v:tmp)s.erase(v);
        for(int v:s)c[q[qr++]=v]=c[y];
        s.clear();
        for(int v:tmp)s.insert(v);
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i=1;i<=m;i++){
        scanf("%d%d", &t1, &t2);
        e[t1].push_back(t2);
        e[t2].push_back(t1);
    }
    for(int i=1;i<=n;i++)s.insert(i);
    for(int i=1;i<=n;i++)if(c[i]==0)solve(i);
    for(int i=1;i<=n;i++)cnt[c[i]]++;
    sort(cnt+1,cnt+1+cc);printf("%d\n",cc);
    for(int i=1;i<=cc;i++)printf("%d ",cnt[i]);
    return 0;
}