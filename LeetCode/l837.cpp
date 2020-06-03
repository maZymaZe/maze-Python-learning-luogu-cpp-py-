#include<algorithm>
#include<cstring>
using namespace std;
double tr[40000]={0},c[40000]={0};
int lowbit(int x){
    return (-x)&x;
}
void upgrade(int pos,double x){
    c[pos]+=x;
    for(int i=pos;i<36000;i+=lowbit(i)){
        tr[i]+=x;
    }
}
double quest(int x){
    double ans=0;
    while(x!=0){
        ans+=tr[x];
        x-=lowbit(x);
    }
    return ans;
}
int main(){

    int N=6, K=1, W=10;
        memset(tr,0,sizeof(tr));memset(c,0,sizeof(c));
        N++;K++;
        upgrade(1,1.0);
        for(int i=2;i<K+W;i++){
            if(i-W>=1){
                upgrade(i,(quest(min(i-1,K-1))-quest(i-W-1))*(1.0/W));
            }
            else{
                upgrade(i,quest(min(i-1,K-1))*(1.0/W));
            }
        }
        double res=0;
        for(int i=K;i<K+W;i++)res+=c[i];
        //return res;
    return 0;
}