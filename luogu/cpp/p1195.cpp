#include<cstdio>
#include<cstring> 
#include<cmath>
#include<algorithm>
using namespace std;
struct ab{
    int x,y,v;
}b[100005];
int cmp(const ab&a,const ab&c)
{
    if(a.v<c.v)return 1;
    else return 0;
}   
int f[10005]={0},n,m,k,cnt=0;
long long sum=0;
int zx(int s)
{
    if(f[s]==s)return s;
    else return f[s]=zx(f[s]);
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++)scanf("%d%d%d",&b[i].x,&b[i].y,&b[i].v);
    sort(b+1,b+1+m,cmp);
    for(int i=1;i<=m;i++)
    {
        if(zx(b[i].x)!=zx(b[i].y)&&cnt<n-k)
        {
            sum+=b[i].v;
            cnt++;
            if(zx(b[i].x)!=zx(b[i].y))f[zx(b[i].x)]=zx(b[i].y);
        }
    }   
    if(cnt==n-k)printf("%lld",sum);
    else printf("No Answer");
    return 0;
}