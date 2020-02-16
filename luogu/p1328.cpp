#include<cstdio>
int main(){
	int j[5][5]={{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
	int i,n,n1,n2,a[203]={0},b[203]={0},c1=0,c2=0;
	scanf("%d%d%d",&n,&n1,&n2);
	for(i=0;i<n1;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n2;i++){
		scanf("%d",&b[i]);
	}
	for(i=0;i<n;i++){
		c1+=j[a[i%n1]][b[i%n2]];
		c2+=j[b[i%n2]][a[i%n1]];
	}
	printf("%d %d",c1,c2);
	return 0;
}
