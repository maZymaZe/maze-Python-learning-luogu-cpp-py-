#include<cstdio>
int mp[1001][1001]={0},ans[1001][1001]={0},n,m,t1,t2,c,d=1,anns[1000001]={0};
int dx[4]={0,0,1,-1},dy[4]={-1,1,0,0};
void flood(int x,int y){
	ans[x][y]=d;
	c++;
	for(int i=0;i<4;i++){
		if(x+dx[i]<=n&&x+dx[i]>0&&y+dy[i]>0&&y+dy[i]<=n&&ans[x+dx[i]][y+dy[i]]==0&&mp[x][y]!=mp[x+dx[i]][y+dy[i]])
			flood(x+dx[i],y+dy[i]);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		scanf("%1d",&mp[i][j]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		if(ans[i][j]==0){
			c=0;
			flood(i,j);
			anns[d]=c;
			d++;
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&t1,&t2);
		printf("%d\n",anns[ans[t1][t2]]);
	}
	return 0;
}
