#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
struct pn{
	int v,s;
}u[100050];
int cmp(const pn& a,const pn& b){
	if(a.v<b.v)return 1;
	else if(a.v==b.v&&a.s>b.s)return 1;
	else return 0;
}

int main(){
	int c=1,n,i,e;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&u[i].s,&u[i].v);
	}
	sort(u+1,u+1+n,cmp);
	e=u[1].v;
	for(i=2;i<=n;i++){
		if(u[i].s>=e){
			c++;
			e=u[i].v;
		}
	}
	printf("%d",c);
	return 0;
}
