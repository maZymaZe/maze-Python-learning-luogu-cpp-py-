#include<cstdio>
int x[14],y[60],z[60],n,ans,anss[14];
void dfs(int l){
	if(l==n+1){
		ans++;
		if(ans<=3){
			for(int i=1;i<=n;i++){
				printf("%d ",anss[i]);
			}
			printf("\n");
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(x[i]==0&&y[i-l+30]==0&&z[i+l]==0){
				anss[l]=i;
				x[i]=1;
				y[i-l+30]=1;
				z[i+l]=1;
				dfs(l+1);
				x[i]=0;
				y[i-l+30]=0;
				z[i+l]=0;
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	dfs(1);
	printf("%d",ans);
	return 0;
} 
