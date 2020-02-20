#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
struct pn{
	int v,s;
}u[1050];
int cmp(const pn& a,const pn& b){
	if(a.v<b.v)return 1;
	else if(a.v==b.v&&a.s<b.s)return 1;
	else return 0;
}

int main(){
	long long sum=0;
	double ans;
	int c=0,n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&u[i].v);
		u[i].s=i;
	}
	sort(u+1,u+1+n,cmp);
	for(i=1;i<=n;i++){
		printf("%d ",u[i].s);
		c=u[i].v*(n-i);
		sum+=c;
	}
	ans=1.0*sum/n;
	printf("\n%.2lf",ans);
	return 0;
}
