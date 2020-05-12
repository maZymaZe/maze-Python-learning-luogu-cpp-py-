#include<cstdio>
#include<cstdlib>
#include<cctype>
int x[5],y[5];
int mul(int a,int b,int c){
    int x1=x[a]-x[c],y1=y[a]-y[c];
    int x2=x[b]-x[c],y2=y[b]-y[c];
    return x1*y2-x2*y1;
}
inline int read() {
	int x = 0 , f = 0 ; char s = getchar() ;
	while ( !isdigit(s) ) f |= s=='-' , s = getchar() ;
	while (  isdigit(s) ) x = (x<<1)+(x<<3)+(s-48) , s = getchar() ;
	return f ? -x : x ;
}
int main(){
    for(int i=1;i<5;i++){
        x[i]=read(),y[i]=read();
    }
    for(int i=1;i<4;i++){
        if(x[i]==x[4]&&y[i]==y[4])
        printf("4"),
        exit(0);
    }
    if(mul(2,4,1)*mul(4,3,1)>=0&&
    mul(1,4,2)*mul(4,3,2)>=0&&
    mul(1,4,3)*mul(4,2,3)>=0){
        for(int i=1;i<=3;i++){
            int t=i%3+1;
            if(mul(i,t,4)==0){
                printf("3");
                exit(0);
            }
        }
        printf("1");
        exit(0);
    }
    printf("2");
    return 0;
}