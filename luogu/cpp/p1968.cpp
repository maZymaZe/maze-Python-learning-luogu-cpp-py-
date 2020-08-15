#include<cstdio>
int n,pre,td;
double res=100;
int main(){
    scanf("%d",&n);
    scanf("%d",&pre);
    for(int i=1;i<n;i++){
        scanf("%d",&td);
        if(td<pre)res=res*pre/td;
        pre=td;
    }
    printf("%.2lf",res);
    return 0;
}
