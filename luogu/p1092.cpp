#include<cstdio>
#include<cstring>
#include<cstdlib>
int n;
int t[300],used[30],p[30],u[30],y;
char s[30][30];
bool ok(){
	int sm;
	for(int i=n;i>=1;i--){
		if(t[s[1][i]]==-1||t[s[2][i]]==-1||t[s[3][i]]==-1)continue;
		sm=t[s[1][i]]+t[s[2][i]];
		if(t[s[3][i]]!=sm%n)
			if(t[s[3][i]]!=(sm+1)%n)return 0;
	}
	return 1;
}
void tr(){
	int jw=0,sm;
	for(int i=n;i>=1;i--){
		sm=t[s[1][i]]+t[s[2][i]]+jw;
		if(t[s[3][i]]!=sm%n)return;
		jw=sm/n;
	}
	for(int i='A';i<='A'+n-1;i++){
		printf("%d ",t[i]);
	}
	exit(0);
}
void dfs(int now){
	if(now>n){
		tr();
	}
	else{
		for(int i=n-1;i>=0;i--){
			if(!used[i]){
				t[p[now]+'A'-1]=i;
				if(ok()){
					used[i]=1;
					dfs(now+1);
					used[i]=0;
				}
			}
		}
		t[p[now]+'A'-1]=-1;
	} 

}
int main(){
	memset(t,-1,sizeof(t));
	scanf("%d",&n);
	for(int i=1;i<=3;i++){
		scanf("%s",s[i]+1);
	}
	for(int j=n;j>0;j--){
		for(int i=1;i<=3;i++){
			if(u[s[i][j]-'A'+1]==0){
			p[++y]=s[i][j]-'A'+1;
			u[s[i][j]-'A'+1]=1;
			}
		}
	}
	
	dfs(1);
	return 0;
} 
