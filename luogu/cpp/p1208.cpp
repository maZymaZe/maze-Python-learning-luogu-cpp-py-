#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
struct pn{
	int v,s;
}u[5050];
int cmp(const pn& a,const pn& b){
	return a.v<b.v;
}

int main(){
	int c=0,t,n,m,i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d",&u[i].v,&u[i].s);
	}
	sort(u+1,u+1+m,cmp);
	i=1;
	while(n!=0){
		if(n>u[i].s){
			n-=u[i].s;
			c+=u[i].s*u[i].v;
		}
		else{
			c+=n*u[i].v;
			break;
		}
		i++;
	}
	printf("%d",c);
	return 0;
}
