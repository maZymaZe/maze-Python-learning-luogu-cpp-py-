#include<cstdio>
int sx,sy,fx,fy,n,m,t,a,b,c=0;
int mp[6][6],xx[4]={1,-1,0,0},yy[4]={0,0,1,-1};
void dfs(int x,int y){
	if(x==fx&&y==fy)c++;
	else{
		for(int i=0;i<=3;i++){
			if(x+xx[i]<=n&&x+xx[i]>0&&y+yy[i]<=m&&y+yy[i]>0&&mp[x+xx[i]][y+yy[i]]==0){
				mp[x+xx[i]][y+yy[i]]=1;
				dfs(x+xx[i],y+yy[i]);
				mp[x+xx[i]][y+yy[i]]=0;
			}
		}
	}
}
int main(){
	scanf("%d%d%d%d%d%d%d",&n,&m,&t,&sx,&sy,&fx,&fy);
	for(int i=1;i<=t;i++){
		scanf("%d%d",&a,&b);
		mp[a][b]=1;
	}
	mp[sx][sy]=1;
	dfs(sx,sy);
	printf("%d",c);
	return 0;
} 
