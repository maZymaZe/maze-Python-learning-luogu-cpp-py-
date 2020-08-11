int x[14],y[60],z[60],ans;
void dfs(int l,int n){
	if(l==n+1)ans++;
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(x[i]==0&&y[i-l+30]==0&&z[i+l]==0){
				x[i]=1;
				y[i-l+30]=1;
				z[i+l]=1;
				dfs(l+1,n);
				x[i]=0;
				y[i-l+30]=0;
				z[i+l]=0;
			}
		}
	}
}
class Solution {
public:
    int totalNQueens(int n) {
        memset(x,0,sizeof(x));
        memset(z,0,sizeof(z));
        memset(y,0,sizeof(y));
        ans=0;
        dfs(1,n);
        return ans;
    }
};