#include<cstdio>
#include<algorithm>
using namespace std;
int a[1004],c[4][4],cnt[4],n,ans=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    for(int i=1;i<=cnt[1];i++){
        c[1][a[i]]++;
    }
    for(int i=cnt[1]+1;i<=cnt[2]+cnt[1];i++){
        c[2][a[i]]++;
    }
    for(int i=cnt[1]+cnt[2]+1;i<=n; i++){
        c[3][a[i]]++;
    }
    int t=min(c[1][2],c[2][1]);
    c[1][2]-=t;
    c[2][1]-=t;
    ans+=t;
    t=min(c[1][3],c[3][1]);
    c[1][3]-=t;
    c[3][1]-=t;
    ans+=t;
    t=min(c[2][3],c[3][2]);
    c[2][3]-=t;
    c[3][2]-=t;
    ans+=t;

    ans+=2*(c[1][2]+c[1][3]);
    printf("%d",ans);
    return 0;
}