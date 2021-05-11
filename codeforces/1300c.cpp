#include<algorithm>
#include<utility>
#include<functional>
#include<cstdio>
using namespace std;
const int NMAX=1e5+10;
int n,a[NMAX],om[40]={0};
int main(){
    scanf("%d",&n);
    for(int i=1; i <=n; i++){
        scanf("%d",&a[i]);
        int p=0,t=a[i];
        while(t){
            p++;
            if(t&1){
                if(om[p]==0)om[p]=i;
                else if(om[p]>0)om[p]=-1;
            }
            t>>=1;
        }
    }
    int bg=1;
    for(int i=35;i>=1;i--){
        if(om[i]>0){bg=om[i];break;}
    }
    printf("%d ",a[bg]);
    for(int i=1; i<=n; i++){
        if(i!=bg)printf("%d ",a[i]);
    }
    return 0;
}