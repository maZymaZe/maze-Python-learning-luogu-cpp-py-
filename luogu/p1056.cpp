#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int r[1003]={0},l[1003]={0};
int cmp(const int& a,const int& b){
	return a>b;
}
int main(){
	int i,j,n,m,k,h,d,x1,x2,y1,y2,rr[1003]={0},ll[1003]={0},mk,mh;
	scanf("%d%d%d%d%d",&n,&m,&k,&h,&d);
	for(i=1;i<=d;i++){
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1==x2){
			if(y1-y2==1){
				ll[y2]++;
				l[y2]++;
				}
			if(y1-y2==-1){
				ll[y1]++;
				l[y1]++;
				}
			}
		if(y1==y2){
			if(x1-x2==1){
				rr[x2]++;
				r[x2]++;
			}
			if(x1-x2==-1){
				rr[x1]++;
				r[x1]++;
			}
		}
	}
	sort(r+1,r+n,cmp);
	mk=r[k];
	for(i=1;i<n;i++){
		if(rr[i]>=mk)printf("%d ",i);
	}
	printf("\n");
	sort(l+1,l+m,cmp);
	mh=l[h];
	for(i=1;i<m;i++){
		if(ll[i]>=mh)printf("%d ",i);
	}
	return 0; 
}
