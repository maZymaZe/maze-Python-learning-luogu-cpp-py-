#include<cstdio>
#include<cstdlib>
int mp[55][55],mmp[55][55],bx,by,fx,fy,face,t[20000],x[20000],y[20000],fc[20000];
int u[55][55][5],head=1,tail=1,m,n,tt;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

int ck(int p,int q){
	return !(mp[p][q]);
}
char fd;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&mp[i][j]);
			 if(mp[i][j]){
                mp[i-1][j-1]=1;
                mp[i-1][j]=1;
                mp[i][j-1]=1;
            }
		}
	}
	scanf("%d%d%d%d",&bx,&by,&fx,&fy);
	scanf("%*c%c",&fd);
	if(bx==fx&&by==fy){
		printf("0");
	}
	else if(mp[bx][by])printf("-1");
	else{
	
	if(fd=='E')face=0;
	if(fd=='S')face=1;
	if(fd=='W')face=2;
	if(fd=='N')face=3;
	t[1]=0;x[1]=bx;y[1]=by;fc[1]=face;
	u[bx][by][face]=1;
	while(head<=tail){
		printf("%d %d %d        %d\n",x[head],y[head],t[head],fc[head]);
		if(x[head]+dx[fc[head]]*1<n&&x[head]+dx[fc[head]]*1>0)
		if(y[head]+dy[fc[head]]*1<m&&y[head]+dy[fc[head]]*1>0)
		if(u[x[head]+dx[fc[head]]*1][y[head]+dy[fc[head]]*1][fc[head]]==0)
		if(ck(x[head]+dx[fc[head]]*1,y[head]+dy[fc[head]]*1))
		{
			tail++;
			u[x[head]+dx[fc[head]]*1][y[head]+dy[fc[head]]*1][fc[head]]=1;
			x[tail]=x[head]+dx[fc[head]]*1;
			y[tail]=y[head]+dy[fc[head]]*1;
			fc[tail]=fc[head];
			t[tail]=t[head]+1;
			if(x[tail]==fx&&fy==y[tail]){
			printf("%d",t[tail]);
			exit(0);
			}
		}
		
		if(x[head]+dx[fc[head]]*2<n&&x[head]+dx[fc[head]]*2>0)
		if(y[head]+dy[fc[head]]*2<m&&y[head]+dy[fc[head]]*2>0)
		if(u[x[head]+dx[fc[head]]*2][y[head]+dy[fc[head]]*2][fc[head]]==0)
		if(ck(x[head]+dx[fc[head]]*1,y[head]+dy[fc[head]]*1))
		if(ck(x[head]+dx[fc[head]]*2,y[head]+dy[fc[head]]*2))
		{
			tail++;
			u[x[head]+dx[fc[head]]*2][y[head]+dy[fc[head]]*2][fc[head]]=1;
			x[tail]=x[head]+dx[fc[head]]*2;
			y[tail]=y[head]+dy[fc[head]]*2;
			fc[tail]=fc[head];
			t[tail]=t[head]+1;
			if(x[tail]==fx&&fy==y[tail]){
			printf("%d",t[tail]);
			exit(0);
			}
		}
		
		if(x[head]+dx[fc[head]]*3<n&&x[head]+dx[fc[head]]*3>0)
		if(y[head]+dy[fc[head]]*3<m&&y[head]+dy[fc[head]]*3>0)
		if(u[x[head]+dx[fc[head]]*3][y[head]+dy[fc[head]]*3][fc[head]]==0)
		if(ck(x[head]+dx[fc[head]]*1,y[head]+dy[fc[head]]*1))
		if(ck(x[head]+dx[fc[head]]*2,y[head]+dy[fc[head]]*2))
		if(ck(x[head]+dx[fc[head]]*3,y[head]+dy[fc[head]]*3))
		{
			tail++;
			u[x[head]+dx[fc[head]]*3][y[head]+dy[fc[head]]*3][fc[head]]=1;
			x[tail]=x[head]+dx[fc[head]]*3;
			y[tail]=y[head]+dy[fc[head]]*3;
			fc[tail]=fc[head];
			t[tail]=t[head]+1;
			if(x[tail]==fx&&fy==y[tail]){
			printf("%d",t[tail]);
			exit(0);
			}
		}
		tt=fc[head]+1;
		if(tt==4)tt=0;
		if(u[x[head]][y[head]][tt]==0){
			tail++;
			u[x[head]][y[head]][tt]=1;
			x[tail]=x[head];
			y[tail]=y[head];
			fc[tail]=tt;
			t[tail]=t[head]+1;
		}
		tt=(fc[head]-1);
		if(tt==-1)tt=3;
		if(u[x[head]][y[head]][tt]==0){
			tail++;
			u[x[head]][y[head]][tt]=1;
			x[tail]=x[head];
			y[tail]=y[head];
			fc[tail]=tt;
			t[tail]=t[head]+1;
		}
		head++;
	}
	printf("-1");
	}
	return 0;
} 
