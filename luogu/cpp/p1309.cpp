#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct p{
	int nm,m,pw;
}pp[200004];
int cmp(const p&a,const p&b){
	if(a.m>b.m)return 1;
	else if(a.m==b.m&&a.nm<b.nm)return 1;
	else return 0;
}
int main(){
	int n,r,k;
	scanf("%d%d%d",&n,&r,&k);
	for(int i=1;i<=2*n;i++){
		scanf("%d",&pp[i].m);
		pp[i].nm=i;
	}
	for(int i=1;i<=2*n;i++){
		scanf("%d",&pp[i].pw);
	}
	for(int i=1;i<=r;i++){
		sort(pp+1,pp+1+2*n,cmp);
		for(int j=1;j<=n;j++){
			if(pp[2*j].pw<pp[2*j-1].pw)pp[2*j-1].m++;
			else pp[2*j].m++;
		}
	}
	sort(pp+1,pp+1+2*n,cmp);
	printf("%d\n",pp[k].nm);
	return 0;
}
