#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct p{
	int nm;
	char mk[200];
}pp[30];
int cmp(const p&a,const p&b){
	if(strlen(a.mk)>strlen(b.mk))return 1;
	else if(strlen(a.mk)==strlen(b.mk)&&strcmp(a.mk,b.mk)>0)return 1;
	else return 0;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",pp[i].mk);
		pp[i].nm=i;
	}
	sort(pp+1,pp+1+n,cmp);
	printf("%d\n%s",pp[1].nm,pp[1].mk);
	return 0;
}
