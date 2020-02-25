#include<cstdio>
template<typename T>
T max(T p,T q){
	if(p>q)return p;
	else return q;
}
int n,pn[40];
long long mk[40][40]={0},t;
void fans(int a,int b){
	int r;
	long long tt;
	if(a==b)printf("%d ",a);
	if(a==b-1)printf("%d %d ",a,b);
	else if(a<b-1){
		for(int k=1;k<=b-a+1;k++){
			if(k==b-a+1)tt=mk[a][b-1]+pn[b];			
			else if(k==1)tt=mk[a+1][b]+pn[a];
			else tt=pn[a+k-1]+mk[a][a+k-2]*mk[a+k][b];
			if(tt==mk[a][b]){
				r=k;
				break;
			}
		} 
		if(r==b-a+1)fans(a,b-1),printf("%d ",b);
		else if(r==1)fans(a+1,b),printf("%d ",a);
		else {
			printf("%d ",a+r-1);
			fans(a,a+r-2);
			fans(a+r,b);
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&pn[i]);
		mk[i][i]=pn[i];
	}
	
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			for(int k=1;k<=i;k++){
				if(k==1)t=mk[j+1][j+i-1]+pn[j];
				else if(k==i)t=mk[j][j+i-2]+pn[j+i-1];
				else t=pn[j+k-1]+mk[j][j+k-2]*mk[j+k][j+i-1];
				mk[j][j+i-1]=max(mk[j][j+i-1],t);
			}
		}
	}
/*	for(int i=0;i<n;i++){
		for(int j=1;j<=n-i;j++){
			printf("%lld ",mk[j][i+j]);
		}
		printf("\n");
	}*/
	printf("%lld\n",mk[1][n]);
	fans(1,n);
	return 0;
}
