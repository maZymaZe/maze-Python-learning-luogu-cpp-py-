#include<cstdio>
#include<set>
#define ll long long
using namespace std;
set<ll>t;
ll n,m,x,ans;
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=n; i++)
	{
		scanf("%lld",&x);
		t.insert(x);
		ans+=x;
	}
	for(int i=1; i<=m; i++)
	{
		scanf("%lld",&x);
		if(t.count(x))ans-=x;
		else ans+=x;
		t.insert(x);
	}
	printf("%lld",ans);
	return 0;
}