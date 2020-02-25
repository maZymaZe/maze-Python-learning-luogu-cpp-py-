#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
struct p{
	char nm[30];
	int m,w;
}pp[120];
int cmp(const p&a,const p&b){
	if(a.m>b.m)return 1;
	else if (a.m==b.m&&a.w<b.w)return 1;
	else return 0;
}
int main(){
	int mn,tm,cm,lw,n,s=0;
	scanf("%d",&n);
	char bg,xb;
	for(int i=1;i<=n;i++){
		scanf("%s %d %d %c %c %d",pp[i].nm,&tm,&cm,&bg,&xb,&lw);
		pp[i].w=i;
		pp[i].m=0;
		mn=0;
		if(tm>80&&lw>0)mn+=8000;
		if(tm>85&&cm>80)mn+=4000;
		if(tm>90)mn+=2000;
		if(tm>85&&xb=='Y')mn+=1000;
		if(cm>80&&bg=='Y')mn+=850;
		s+=mn;
		pp[i].m=mn;
	}
	sort(pp+1,pp+1+n,cmp);
	printf("%s\n%d\n%d",pp[1].nm,pp[1].m,s);
	return 0;
}
