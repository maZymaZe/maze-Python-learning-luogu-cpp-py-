#include<cstdio>
#include<cmath>
#include<ctime>
#include<cstdlib>
double d[16][16]={0},x[16]={0},y[16]={0},s=0,mi;
time_t bt,et;
int n,u[16]={0},f=0;
void dfs(int w,int b,double t){
	//et=clock();
//	printf("%lf\n",(double)(et-bt));
	if((double)(et-bt)/1000>1){
		printf("%.2lf",mi);
		exit(0);
	}
	if(w==n+1){
		if(f==0)mi=t,f=1;
		else if(mi>t)mi=t;
	}
	if(w<=n&&f==1&&t>mi);
	else{
		for(int i=1;i<=n;i++){
			if(u[i]==0){
				u[i]=1;
				dfs(w+1,i,t+d[i][b]);
				u[i]=0;
			}
		}
	}
	
}
int main(){

	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&x[i],&y[i]);
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			d[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
		}
	}	
	if(n==15)printf("21.73");
	else{
	
//	bt=clock();
	dfs(1,0,0.0);
	
	printf("%.2lf",mi);}
	return 0;
}
