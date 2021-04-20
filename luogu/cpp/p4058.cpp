#include<cstdio>
#define ull unsigned long long 
using namespace std;
ull n,s,l,h[200005],a[200005],hnow[200005];
bool check(ull x)
{
    for(ull i=1;i<=n;i++)
        hnow[i]=h[i]+x*a[i];
    ull sum=0;
    for(ull i=1;i<=n;i++)
    {
        if(hnow[i]>=l)
            sum+=hnow[i];
    }
    return sum>=s;
}
int main()
{
	scanf("%llu%llu%llu",&n,&s,&l);
	for(ull i=1;i<=n;i++) scanf("%llu",&h[i]);
	for(ull i=1;i<=n;i++) scanf("%llu",&a[i]);
	if(check(0))
	{
		puts("0");
		return 0;
	}
	ull l=1,r=5e18;
	while(l<r)
	{
		ull mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%llu",l);
	return 0;
}