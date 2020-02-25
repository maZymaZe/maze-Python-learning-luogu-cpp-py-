#include<cstdio>
int dx[8]={-2,-2,-1,1,2,2,1,-1},dy[8]={-1,1,2,2,1,-1,-2,-2};
int n,m,bx,by,x[160002],y[160002];
int ans[405][405],head=1,tail=1;
int main(){
	scanf("%d%d%d%d",&n,&m,&bx,&by);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ans[i][j]=-1;
		}
	}
	ans[bx][by]=0;
	x[1]=bx;y[1]=by;
	while(head<=tail){
		for(int i=0;i<=7;i++){
			if(x[head]+dx[i]>0&&x[head]+dx[i]<=n&&y[head]+dy[i]>0&&dy[i]+y[head]<=m)
			if(ans[x[head]+dx[i]][y[head]+dy[i]]==-1){
				tail++;
				x[tail]=x[head]+dx[i];
				y[tail]=y[head]+dy[i];
				
				ans[x[tail]][y[tail]]=ans[x[head]][y[head]]+1;
			}
		}
		head++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%-5d",ans[i][j]);
		}
		printf("\n");
	}
	return 0; 
}

