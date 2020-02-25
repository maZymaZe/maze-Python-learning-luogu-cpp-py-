#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct p{
	int nm,c,m,e,to;
}pp[305];
int cmp(const p&a,const p&b){
	if(a.to>b.to)return 1;
	else if(a.to==b.to&&a.c>b.c)return 1;
	else if(a.to==b.to&&a.c==b.c&&a.nm<b.nm)return 1;
	else return 0;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&pp[i].c,&pp[i].m,&pp[i].e);
		pp[i].to=pp[i].c+pp[i].e+pp[i].m;
		pp[i].nm=i;
	}
	sort(pp+1,pp+1+n,cmp);
	for(int i=1;i<=5;i++)
	printf("%d %d\n",pp[i].nm,pp[i].to);
	return 0;
}
