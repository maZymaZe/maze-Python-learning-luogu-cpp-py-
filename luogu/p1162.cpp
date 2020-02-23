#include<cstdio>
int mp[31][31]={0},n,dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
void flood(int x,int y){
	if (mp[x][y]==0){
		mp[x][y]=-1;
		for(int i=0;i<4;i++){
			if(x+dx[i]<=n&&x+dx[i]>0&&y+dy[i]>0&&y+dy[i]<=n)
			flood(x+dx[i],y+dy[i]);
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&mp[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		flood(1,i);
		flood(n,i);
		flood(i,1);
		flood(i,n);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mp[i][j]==-1)printf("0 ");
			if(mp[i][j]==1)printf("1 ");
			if(mp[i][j]==0)printf("2 ");
		}
		printf("\n");
	}
	return 0;
}
