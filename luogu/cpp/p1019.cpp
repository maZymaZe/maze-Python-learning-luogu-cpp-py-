#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
char w[70][70],z;
int pls[70][70],mx=0,usd[70],n,l[70];
void dfs(int ll,int now){
	if(ll>mx)mx=ll;
	for(int i=1;i<=n;i++){
		if(pls[now][i]>0&&usd[i]<2){
			usd[i]++;
			dfs(ll+pls[now][i],i);
			usd[i]--;
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>w[i];
		l[i]=strlen(w[i]);
	}
	int a,b,c,f;
	cin>>z;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			
			if(l[i]>l[j])c=l[j];
			else c=l[i];
			
			for(int k=1;k<c;k++){
				f=1;
				for(int h=1;h<=k;h++){
					if(w[i][l[i]-k+h-1]!=w[j][h-1])
					{
						f=0;
						break;
					}
				}
				if(f==1){
					pls[i][j]=l[j]-k;
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(w[i][0]==z){
			usd[i]++;
			dfs(l[i],i);
			memset(usd,0,sizeof(usd));
		}
	}
	printf("%d",mx);
	return 0;
}
