#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
struct p{
	int nm,mk;
}pp[20040];
int cmp(const p&a,const p&b){
	if(a.mk>b.mk)return 1;
	else if (a.mk==b.mk&&a.nm<b.nm)return 1;
	else return 0;
}
int main(){
	int n,e[16],k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=10;i++)scanf("%d",&e[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&pp[i].mk);
		pp[i].nm=i;
	}
	sort(pp+1,pp+1+n,cmp);
	for(int i=1;i<=n;i++){
		pp[i].mk+=e[(i-1)%10+1];
	}
	sort(pp+1,pp+1+n,cmp);
	for(int i=1;i<=k;i++)
		printf("%d ",pp[i].nm);
	return 0;
}
