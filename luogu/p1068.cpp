#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
struct p{
	int nm,mk;
}pp[6000];
int cmp(const p&a,const p&b){
	if(a.mk>b.mk)return 1;
	else if (a.mk==b.mk&&a.nm<b.nm)return 1;
	else return 0;
}
int main(){
	int n,m,c=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&pp[i].nm,&pp[i].mk);
	}
	sort(pp+1,pp+1+n,cmp);
	m=(int)(m*1.5);
	if(m<=n){
		for(int i=1;i<=n;i++){
			if(pp[i].mk>=pp[m].mk)c++;
		}
		printf("%d %d\n",pp[m].mk,c);
		for(int i=1;i<=c;i++){
			printf("%d %d\n",pp[i].nm,pp[i].mk);
			
		}
	}
	return 0;
}
