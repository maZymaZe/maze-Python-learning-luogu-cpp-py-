#include <cstdio>
#include <algorithm>
using namespace std;
int ck[100005];
struct pr{
    int v,x,w;
    bool operator <(const pr&x){ return this->v<x.v;}
}l[100005],r[100005];
int cmp(const pr&a,const pr&b){
    return a.x<b.x;
}
int cmp2(const pr&a,const pr&b){
    return a.v<b.v;
}
int n, a[110005], c[110005];
void j(int i, int x)
{
    for (int z = i; z <= 100005; z += -z & z)
        c[z] += x;
}
int he(int x)
{
    int s = 0;
    for (int k = x; k > 0; k -= -k & k)
        s += c[k];
    return s;
}
int main()
{
    long long ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &l[i].v);
        l[i].x = i;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &r[i].v);
        r[i].x = i;
    }
    sort(l+1,l+1+n);
    for(int i = 1; i <= n; i++){
        ck[i]=l[i].x;
    }
    sort(r+1,r+1+n);
    for(int i = 1; i <= n; i++){
        r[i].w=i;
    }
    sort(r+1,r+1+n,cmp);
    for(int i=1;i<=n;i++)a[i]=ck[r[i].w];
    for (int i = n; i >= 1; i--)
    {
        j(a[i], 1);
        ans += he(a[i] - 1);
        ans%=99999997;
    }
    printf("%lld", ans);
    return 0;
}
