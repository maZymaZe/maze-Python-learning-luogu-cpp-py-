#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
struct pn{
	int v,x,y;
}u[500];
int cmp(const pn& a,const pn& b){
	return a.v>b.v;
}
int p=0;
int vn(int n){
	if(n==1){
		return 2*u[1].x+1;
	}
	else if(n<=p){
		return u[n].x+1+abs(u[n].x-u[n-1].x)+abs(u[n].y-u[n-1].y);
	}
}
int st(int n){
	if(n==1){
		return u[1].x+1;
	}
	else if(n<=p){
		return 1+abs(u[n].x-u[n-1].x)+abs(u[n].y-u[n-1].y);
	}
}
int main(){
	int c=0,s=0,t,n,m,i,j,tt;
	scanf("%d%d%d",&n,&m,&t);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&tt);
			if(tt){
				c++;
				p++;
				u[p].v=tt;
				u[p].x=i;
				u[p].y=j;	
			}
		}
	}
	sort(u+1,u+1+p,cmp);
	for(i=1;i<=p;i++)
	{
		if(t>=vn(i)){
			t-=st(i);
			s+=u[i].v;
		}
		else break;
	}
	printf("%d",s);
	return 0;
}
