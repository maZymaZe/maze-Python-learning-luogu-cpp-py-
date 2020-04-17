#include<cstdio>
#include<algorithm>
#define MAX 100004
using namespace std;
int f[MAX],n,ans=MAX,siz[MAX],top,q[MAX];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&f[i]);
    sort(f+1,f+n+1);
    for(int i=1;i<=n;i++){
        int pos=lower_bound(q+1,q+1+top,f[i])-q;
        while(q[pos+1]==f[i]&&pos<top)pos++;
        if(pos>top||q[pos]!=f[i]){
            top++;
            siz[top]=1;
            q[top]=f[i]+1;
        }
        else siz[pos]++,q[pos]++;
    }
    for(int i=1;i<=top;i++)ans=min(ans,siz[i]);
    printf("%d\n",ans);
    return 0;
}
