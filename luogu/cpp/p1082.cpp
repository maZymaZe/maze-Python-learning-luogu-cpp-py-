#include<cstdio>
int x,y,k;
void exgcd(int a,int b){
    if(b==0){
        x=1,y=0;
        return;
    }
    exgcd(b,a%b);
    k=x;
    x=y;
    y=k-a/b*y;
    return;
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    exgcd(a,b);
    printf("%d",(x%b+b)%b);
    return 0;
}