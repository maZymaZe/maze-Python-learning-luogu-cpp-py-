#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct p{
	char mk[200];
}pp[30];
int cmp(const p&a,const p&b){
	char tmp[20]={0};
	memset(tmp,0,sizeof(tmp));
	if	(strlen(a.mk)==strlen(b.mk)){
		return strcmp(a.mk,b.mk)>0;
	}
	else if	(strlen(a.mk)>strlen(b.mk)){
		for(int i=0;i<strlen(a.mk);i++)
		tmp[i]=b.mk[i%strlen(b.mk)];
		
		return strcmp(a.mk,tmp)>0;
	}
	else{
		for(int i=0;i<strlen(b.mk);i++)
		tmp[i]=a.mk[i%strlen(a.mk)];
		return strcmp(tmp,b.mk)>0;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",pp[i].mk);
	}
	sort(pp+1,pp+1+n,cmp);
	for(int i=1;i<=n;i++)
	printf("%s",pp[i].mk) ;
	return 0;
}
