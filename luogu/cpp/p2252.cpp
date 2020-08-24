#include<cmath>
#include<cstdio>
void swap(int &a,int &b){int temp=a;a=b;b=temp;}
int a,b;
const double d=(sqrt(5.0)+1.0)/2.0;
int main(){
    scanf("%d%d",&a,&b);
    if(a<b)swap(a,b);
    if(b==int(d*(double)(a-b)))printf("0");
    else printf("1");
    return 0;
}