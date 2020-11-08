#include<cstdio>
#include<cmath>
int n,t,nt,p;
int main(){
    scanf("%d", &n);
    int b=floor(sqrt(n));
    nt=n;t=0;
    if(b*b<n)b++;
    nt-=b-1;
    for(int i=1;i<=n;i++){
        while(nt+t<=0)t++;
        printf("%d ",nt+t);
        t++;
        if(t==b){
            nt-=b;
            t=0;
        }
    }
    return 0;
}