#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct p{
	int xx,yy,hh;
}pp[10002];
int cmp(const p&a,const p&b){
	return a.hh>b.hh;
}
int mp[102][102],ans[102][102],n,m,c=0,mx=0;
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
void flood(int a,int b){
	for(int i=0;i<4;i++){
		if(a+dx[i]<=n&&a+dx[i]>0&&b+dy[i]>0&&b+dy[i]<=m){
			if(mp[a][b]>mp[a+dx[i]][b+dy[i]]){
				if(ans[a][b]+1>ans[a+dx[i]][b+dy[i]]){
					ans[a+dx[i]][b+dy[i]]=ans[a][b]+1;
					flood(a+dx[i],b+dy[i]);
				}
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			c++;
			scanf("%d",&mp[i][j]);
			pp[c].hh=mp[i][j];
			pp[c].xx=i;
			pp[c].yy=j;
		}
	}
	sort(pp+1,pp+1+c,cmp);
	for(int i=1;i<=c;i++){
		if(ans[pp[i].xx][pp[i].yy]==0)
		{
			ans[pp[i].xx][pp[i].yy]=1;
			flood(pp[i].xx,pp[i].yy);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]>mx)mx=ans[i][j];
		}
	}
	printf("%d",mx);
	return 0;
}
