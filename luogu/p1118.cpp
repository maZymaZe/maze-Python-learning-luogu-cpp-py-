#include<cstdio>
#include<cstdlib>
int yh[13][13]={0},ans[13]={0},s=0,u[13]={0},n,ns;
void dfs(int w){
	if(w==n+1)
		if(s==ns){
			for(int i=1;i<=n;i++){
				printf("%d ",ans[i]);
			}
			exit(0);
		}
	if(s>=ns);
	else{
		for(int i=1;i<=n;i++){
			if(u[i]==0){
				ans[w]=i;
				u[i]=1;
				s+=yh[n][w]*i;
				dfs(w+1);
				ans[w]=0;
				u[i]=0;
				s-=yh[n][w]*i;
			}
		}
	}
	
}
int main(){
	scanf("%d%d",&n,&ns);
	for(int i=1;i<=n;i++){
		yh[i][1]=1;
		yh[i][i]=1;
	}
	for(int i=3;i<=n;i++){
		for(int j=2;j<i;j++){
			yh[i][j]=yh[i-1][j-1]+yh[i-1][j];
		}
	}
	dfs(1);
	return 0;
} 
